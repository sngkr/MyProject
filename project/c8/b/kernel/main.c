#include "print.h"
#include "init.h"
#include "thread.h"
#include "interrupt.h"
#include "console.h"
// #include "ioqueue.h"
// #include "keyboard.h"
void k_thread_a (void*);
void k_thread_b (void*);

int main(void)
{
   put_str("I am kernel\n");
   init_all();

   // void* addr = get_kernel_pages(3);
   // put_str("\n get_kernel_page start vaddr is ");
   // put_int((uint32_t) addr);
   // put_str("\n");

   // thread_start("k_thread_a", 31, k_thread_a, "argA ");

   thread_start("k_kernel_a", 31, k_thread_a, "argA");
   thread_start("k_kernel_b", 31, k_thread_b, "argB");
   intr_enable();
   while(1)
   {
      // intr_disable();
      // put_str("Main ");
      // intr_enable();
     // console_put_str("Main ");
   }
   return 0;
}

/* 在线程中运行的函数 */

void k_thread_a(void* arg)
{
   // void * 表示通用参数，需要什么参数可以自己转换

   char * para = arg;
   while(1)
   {
      enum intr_status old_status = intr_disable();
      if(!ioq_empty(&kbd_buf))
      {
         console_put_str("11");
         console_put_str(arg);
         char  byte = ioq_getchar(&kbd_buf);
         console_put_char(byte);
      }
      intr_set_status(old_status);
      // intr_disable();
      // put_str(para);
      // // intr_enable();
      // console_put_str(para);
   }
}

void k_thread_b(void * arg)
{
   char* para = arg;
   while(1)
   {
      enum intr_status old_status = intr_disable();
      if(!ioq_empty(&kbd_buf))
      {
         console_put_str("22");
         console_put_str(arg);
         char  byte = ioq_getchar(&kbd_buf);
         console_put_char(byte);
      }
      intr_set_status(old_status);
      // // intr_disable();
      //  put_str(para);
      // // intr_enable();
      // console_put_str(para);
   }
}