/*
 * @Author: your name
 * @Date: 2021-06-20 12:56:05
 * @LastEditTime: 2021-06-20 12:58:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \MyProject\Os Experiment\SXProblem.cpp
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
 
void *thread1(void *);
void *thread2(void *);
 
int i=1;
int main(void)
{
    pthread_t t_a;
    pthread_t t_b;
 
    pthread_create(&t_a,NULL,thread2,(void *)NULL);/*create thread t_a*/
    pthread_create(&t_b,NULL,thread1,(void *)NULL); /*create thread t_b*/
    pthread_join(t_b, NULL);/*wait for exit of t_b*/
    pthread_join(t_a, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    exit(0);
}
 
void *thread1(void *junk)
{
    for(i=1;i<=9;i++)
    {
        pthread_mutex_lock(&mutex);
        if(i%3==0)
             pthread_cond_signal(&cond);
        else
             printf("thread1 running, i = %d\n",i);
        pthread_mutex_unlock(&mutex);
        Sleep(2);
    }
}
 
 
void *thread2(void *junk)
{
 while(i<9)
{
pthread_mutex_lock(&mutex);
if(i%3!=0)
pthread_cond_wait(&cond,&mutex);/*..*/
printf("thread2 running, i = %d\n",i);
 pthread_mutex_unlock(&mutex);
Sleep(2);
}
} 