#ifndef __THREAD_THREAD_H
#define __THREAD_THREAD_H
#include "stdint.h"
#include "list.h"
#include "bitmap.h"
#include "memory.h"
/* 自定义通用函数类型 */
typedef void thread_func(void*);

/* 进程或者线程的状态 */
enum task_status
{
    TASK_RUNNING,
    TASK_READY,
    TASK_BLOCKED,
    TASK_WAITING,
    TASK_HANGING,
    TASK_DIED
};

/* 中断栈 */
/*
中断时保护上下文环境
栈的位置固定 页的最顶端 
 */

 struct intr_stack
 {
     uint32_t vec_no;
     uint32_t edi;
     uint32_t esi;
     uint32_t ebp;
     uint32_t esp_dummy;//dummy(傀儡)
     uint32_t ebx;
     uint32_t edx;
     uint32_t ecx;
     uint32_t eax;
     uint32_t gs;
     uint32_t fs;
     uint32_t es;
     uint32_t ds;

     /* 以下由cpu从低特权级进入高特权级时压入 */

     uint32_t err_code;
     void (*eip)(void);//左边括号迫使eip成为一个函数指针，所指的函数返回void类型的值
     uint32_t cs;
     uint32_t eflags;
     void* esp;
     uint32_t ss;
 };


/* 线程栈 */
/* 
实际位置取决于运行情况
仅用在switch_to 时保存线程环境
 */

 struct thread_stack
 {
     uint32_t ebp;
     uint32_t ebx;
     uint32_t edi;
     uint32_t esi;
 
    /* 线程第一次执行的时候，eip指向的是将要调用的函数kernel_thread，其他时候eip执行的是switch_to的返回地址 */
    void(*eip)(thread_func * func, void* func_arg);

    /* *************以下只供用第一次被调度上cpu时使用 */
    void (*unused_retaddr);
    thread_func* function;//kernel_thread所调用的函数名
    void* func_arg;//kernel_thread所调用的函数所需要的参数

 };
/* ***************************************** */

/* *********PCB********* */
struct task_struct
{
    uint32_t * self_kstack;//内核进程都用自己的内核栈
    enum task_status status;
    uint8_t priority;
    char name[16];
    uint32_t stack_magic;//魔数，栈的边界标记，防溢出
    uint8_t ticks; //执行的时间滴答数
    /* 页表 */
    uint32_t * pgdir;//页表的虚拟地址

    /* 任务执行了多少个滴答 */
    uint32_t elapsed_ticks;

    /* general_tag 的作用是线程在一般队列的节点 */
    struct list_elem general_tag;

    /* 用于thread_all_list中的节点 */
    struct list_elem all_list_tag;

    /* **********6/3******* */
    struct virtual_addr userprog_vaddr; //进程的虚拟地址
};
void thread_create(struct task_struct* pthread, thread_func function, void* func_arg);
void init_thread(struct task_struct* pthread, char* name, int prio);
struct task_struct* thread_start(char* name, int prio, thread_func function, void* func_arg);
struct task_struct* running_thread(void);
void schedule(void);
void thread_init(void);
void thread_block(enum task_status stat);
void thread_unblock(struct task_struct* pthread);
#endif

