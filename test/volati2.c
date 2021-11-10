#include<stdio.h>

int main(){
    volatile int a=0;

    int i = a;
    int j = a;
    return 0;
}