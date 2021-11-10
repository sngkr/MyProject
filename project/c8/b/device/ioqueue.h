#ifndef __DEVICE_IOQUEUE_H
#define __DEVICE_IOQUEUE_H
#include "stdint.h"
#include "thread.h"
#include "sync.h"
#define bufsize 64
struct ioqueue
{
    struct lock lock;
    struct task_struct* producer;
    struct task_struct* consumer;
    char buf[bufsize];//缓冲区
    int32_t head;
    int32_t tail;
};
// struct task_struct
// {
//     uint32_t * self_kstack;//内核进程都用自己的内核栈
//     enum task_status status;
//     uint8_t priority;
//     char name[16];
//     uint32_t stack_magic;//魔数，栈的边界标记，防溢出
//     uint8_t ticks; //执行的时间滴答数
 
//     /* 任务执行了多少个滴答 */
//     uint32_t elapsed_ticks;

//     /* general_tag 的作用是线程在一般队列的节点 */
//     struct list_elem general_tag;

//     /* 用于thread_all_list中的节点 */
//     struct list_elem all_list_tag;

//     uint32_t * pgdir;//页表的虚拟地址
// };

//函数声明

void ioqueue_init(struct ioqueue* ioq);
bool ioq_full(struct ioqueue* ioq);
char ioq_getchar(struct ioqueue* ioq);
void ioq_putchar(struct ioqueue* ioq, char type);

#endif