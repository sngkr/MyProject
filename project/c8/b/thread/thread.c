#include "thread.h"
#include "stdint.h"
#include "string.h"
#include "global.h"
#include "debug.h"
#include "interrupt.h"
#include "print.h"
#include "memory.h"

#define PG_SIZE 4096

/* *****************************5/26****************************** */
struct task_struct * main_thread;//PCB定义
struct list thread_ready_list;//就绪队列
struct list thread_all_list;
static  struct list_elem* thread_tag; // 临时节点 

extern void switch_to(struct task_struct * cur , struct task_struct * next);//外部可以引用

// 获取PCB指针
struct task_struct* running_thread()
{   
    uint32_t esp;
    asm("mov %%esp, %0" : "=g"(esp));
    // 取起始地址
    return  (struct task_struct *)(esp & 0xfffff000);
}

/* kernel_thread 执行 function(func_arg) */
static void kernel_thread(thread_func * function, void* func_arg)
{
    // 开中断，避免时钟中断被屏蔽
    intr_enable();
    function(func_arg);
}


/* *****************************5/26****************************** */
/*  kernel_thread  execute function(func_arg)*/
// static void kernel_thread(thread_func* function , void *func_arg)
// {
//     function(func_arg);
// }

/* 初始化线程栈thread_stack 相应位置 */
void thread_create(struct task_struct* pthread, thread_func function, void* func_arg) {
   /* 先预留中断使用栈的空间,可见thread.h中定义的结构 */
   pthread->self_kstack -= sizeof(struct intr_stack);

   /* 再留出线程栈空间,可见thread.h中定义 */
   pthread->self_kstack -= sizeof(struct thread_stack);
   struct thread_stack* kthread_stack = (struct thread_stack*)pthread->self_kstack;
   kthread_stack->eip = kernel_thread;
   kthread_stack->function = function;
   kthread_stack->func_arg = func_arg;
   kthread_stack->ebp = kthread_stack->ebx = kthread_stack->esi = kthread_stack->edi = 0;
}

/* 初始化线程基本信息 */
void init_thread(struct task_struct* pthread, char* name, int prio) {
   memset(pthread, 0, sizeof(*pthread));
   strcpy(pthread->name, name);

// 有mian函数，也将他封装位一个线程
    if(pthread == main_thread)
    {
        pthread->status = TASK_RUNNING;
    }
    else
    {
        pthread->status = TASK_READY;
    }

    pthread->pgdir = NULL;
    pthread->ticks = prio;
    pthread->elapsed_ticks = 0;
//    pthread->status = TASK_RUNNING; 
   pthread->priority = prio;
/* self_kstack是线程自己在内核态下使用的栈顶地址 */
   pthread->self_kstack = (uint32_t*)((uint32_t)pthread + PG_SIZE);
   pthread->stack_magic = 0x19870916;	  // 自定义的魔数
}

/* 创建一优先级为prio的线程,线程名为name,线程所执行的函数是function(func_arg) */
struct task_struct* thread_start(char* name, int prio, thread_func function, void* func_arg) {
/* pcb都位于内核空间,包括用户进程的pcb也是在内核空间 */
   struct task_struct* thread = get_kernel_pages(1);

   init_thread(thread, name, prio);
   thread_create(thread, function, func_arg);

    /* 如果不在 thread_ready_list*/
    ASSERT(!elem_find(&thread_ready_list, & thread->general_tag));
    list_append(&thread_ready_list, & thread->general_tag);

    /* 如果不在thread_all_list */
    ASSERT(!elem_find(&thread_all_list, & thread->all_list_tag));
    list_append(&thread_all_list, & thread->all_list_tag);

//    asm volatile ("movl %0, %%esp; pop %%ebp; pop %%ebx; pop %%edi; pop %%esi; ret" : : "g" (thread->self_kstack) : "memory");
   /* 
   g: 通用约束，表示内存和寄存器都可以
   memory :强制 gcc 编译器假设 RAM 所有内存单元均被汇编指令修改，
        这样 cpu 中的 registers 和 cache 中已缓存的内存单元中的数据将作废。cpu 将不得不在需要的时候重新读取内存中的数据。
        这就阻止了 cpu 又将 registers, cache 中的数据用于去优化指令，而避免去访问内存。
—
    */
   
   return thread;
}

/* make main_thread */
static void make_main_thread(void)
{
    // loader.S 进入内核 mov esp ， 0xc009f000
    // 上面地址是已经预留pcb的  那么&pcb = 0xc009e000
    main_thread = running_thread();
    init_thread(main_thread, "main", 31);


    // main是当前线程，他只可以加入thread_all_list

    ASSERT(!elem_find(&thread_all_list, & main_thread->all_list_tag));
    list_append(&thread_all_list, & main_thread->all_list_tag); 
}

/* ***********5/26************ */
void schedule()

{
    ASSERT(intr_get_status() == INTR_OFF);

    struct task_struct * cur = running_thread();
    if(cur->status == TASK_RUNNING)
    {
        /* 时间片用完*/
        ASSERT(!elem_find(&thread_ready_list, & cur->general_tag));
        list_append(&thread_ready_list, &cur->general_tag);
        // 重置线程的状态
        cur->status = TASK_READY;

        cur->ticks = cur->priority;
    }
    else
    {
        /* 若线程需要某个事件发生才能继续上cpu运行， 不需要将其加入队列，因为当前线程不再就绪队列 */
    }
    ASSERT(!list_empty(&thread_ready_list));
    thread_tag = NULL;


    /* 将thread_ready_list中的第一个就绪线程弹出，准备将他调度上cpu */
    thread_tag = list_pop(&thread_ready_list);
    //得到下一个进程的地址
    struct task_struct * next = elem2entry(struct task_struct, general_tag, thread_tag);
    next->status = TASK_RUNNING;
    switch_to(cur, next);

}

/* 初始化线程的环境 */
void  thread_init(void)
{
    put_str("thread_init start\n");
    list_init(&thread_ready_list);
    list_init(&thread_all_list);

    /* 将当前mian函数创建成线程 */
    make_main_thread();
    put_str("thread_init done\n");
}

/* ***********5/27************* */
// 线程自己阻塞
void thread_block(enum task_status stat)
{
    ASSERT(((stat == TASK_BLOCKED) || (stat == TASK_WAITING) || (stat == TASK_HANGING)));
    enum intr_status old_status = intr_disable();   
    struct task_struct * cur_thread = running_thread();
    cur_thread -> status = stat;//更改进程当前的状态
    schedule();

    /* 当前进程解除阻塞以后才会运行下面的intr_set_status */
    intr_set_status(old_status);
}

// 线程解除阻塞
void thread_unblock(struct task_struct* pthread) {
   enum intr_status old_status = intr_disable();
   ASSERT(((pthread->status == TASK_BLOCKED) || (pthread->status == TASK_WAITING) || (pthread->status == TASK_HANGING)));
   if (pthread->status != TASK_READY) {
      ASSERT(!elem_find(&thread_ready_list, &pthread->general_tag));
      if (elem_find(&thread_ready_list, &pthread->general_tag)) {
	 PANIC("thread_unblock: blocked thread in ready_list\n");
      }
      list_push(&thread_ready_list, &pthread->general_tag);    // 放到队列的最前面,使其尽快得到调度
      pthread->status = TASK_READY;
   } 
   intr_set_status(old_status);
}
