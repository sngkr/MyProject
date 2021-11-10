#include"string.h"
#include"global.h"
#include"debug.h"

//函数memcmp！！

// 字符串操作函数
// typedef unsigned char uint8_t;

// char  8
// short 16
// int   32
// long  64

// 将dst_起始的size个字节置为value 
void memset(void* dst_, uint8_t value , uint32_t size)
{
   //空的的话调用debug
   ASSERT(dst_ != NULL);
   // 好习惯：强制类型转换
   uint8_t* dst = (uint8_t*)dst_;
   while(size-- > 0)
      {
         *dst++ = value;
      }

}

// 将src_起始的size个字节复制到dst_
void memcpy(void* dst_, const void* src_, uint32_t size)
{
   //空的的话调用debug
   ASSERT(dst_ != NULL && src_ != NULL);
   // 好习惯：强制类型转换
   uint8_t* dst = dst_;
   const uint8_t* src = src_;
   while(size-- > 0)
   {
      *dst++ = *src++;
   }
}


//连续比较以地址a_和地址b_开头的size个字节， 相等返回0.不相等返回1
int memcmp(const void* a_, const void* b_, uint32_t size)
{
   //char 有三种 char 、signed char 、 unsigned char
   // 是signed还是unsigned取决于编译器，作者使用char可能就是为了防止这种错误发生？？？？？？？为什么上面不用
   //我先不更改
   const char* a = a_;
   const char* b = b_;
   // 这个为什么不先判断
   ASSERT(a != NULL && b != NULL);
   while(size-- > 0)
   {
      if(*a != *b)
      {
         return *a>*b ? 1 : -1;
      }
      a++; 
      b++;
   }
   return 0;
}

// 将字符串从src_ 拷贝到 dst_
char* strcpy(char* dst_, const char* src_)
{
   ASSERT(dst_ != NULL && src_ != NULL);
   char* r = dst_;
   while((*dst_++ = *src_++));
   return r;
}
// 返回字符串的长度
uint32_t strlen(const char* str)
{
   ASSERT(str != NULL);
   const char* p = str;
   while(*p++);
   return(p- str -1);
   //第一次见这种方法emmmm
}

// 比较两个字符串 相等返回0 小于a<b返回-1, a>b返回1
int8_t strcmp(const char*a, const char* b)
{
   ASSERT(a !=NULL && b != NULL);
   while(*a != 0 && *a != *b)
   {
      a++;
      b++;
   }
   // 如果*a<*b return -1
   return *a < *b ? -1 : *a > *b;

}


// 从左向有查找字符串str中首次出现字符ch的地址
char * strchr(const char* str, const uint8_t ch)
{
   ASSERT(str != NULL);
   while(*str != 0)
   {
      if(*str == ch)
      {
         // 好习惯：强制类型转换
         return (char*)str;//否则编译器会报const属性丢失
      }
      str++;
   }
   return NULL;
}

//从后往前查出字符串中首次出现ch的地址
char* strrchr(const char* str, const uint8_t ch)
{
   ASSERT(str != NULL);
   const char* last_char = NULL;
   // 从头到尾遍历，存在ch就会更新last_char的值一次，
   while(*str != 0)
   {
      if(*str == ch)
      {
         last_char = str;
      }
      str++;
   }
   return (char*)last_char;
}

//将字符串src_ 拼接到dst_ 后面  返回拼接的串地址
char * strcat(char* dst_, const char* src_ )
{
   ASSERT(dst_ != NULL && src_ != NULL);
   char *str = dst_;
   //到达dst_的尾巴
   while(*str++);
   --str;
   // 将src_ 的内容接到 dst_后面
   while((*str++ = *src_++));

   return dst_;
}

// ch在字符串str中出现的次数
uint32_t strchrs(const char* str, uint8_t ch)
{
   ASSERT(str != NULL);
   uint32_t ch_cnt = 0;
   // 避免更改
   const char* p = str;
   while(*p != 0)
   {
      if(*p == ch)
      {
         ch_cnt++;
      }
      p++;
   }

   return ch_cnt;
}

