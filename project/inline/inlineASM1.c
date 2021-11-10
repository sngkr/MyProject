#include<stdio.h>
int in_a=1, in_b=2, out_sum;
void main()
{
	asm("pusha; \
			movl in_a, %eax; \
			movl in_b, %ebx; \
			add %ebx, %eax; \
			movl %eax, out_sum; \
			popa");
		printf("sum is %d\n",out_sum);
}
