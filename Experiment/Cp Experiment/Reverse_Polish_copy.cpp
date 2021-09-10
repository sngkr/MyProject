#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#define max 100
/* 函数 */
void calculate(char suffix[size]);
void transition(int p);
/* 变量 */
char suffix[size];      //存储后缀表达式
char str[size];   	   //存储原算术表达式
char stack[size];       //计算时使用的栈
/*将算术表达式转化为后缀表达式*/
void transition(int p)
{        

    char ch;
    int sum,i=0,suffix_size=0,top=0;
    printf("\n算数表达式：");
    scanf("%s",str);		//获取用户输入的表达式
    printf("%s",str);
    sum=strlen(str);
    	i=0,suffix_size=0;
        ch=str[i];i++;
        while(ch!='#'){
            switch(ch){
	            case '(':                 
	                top++;stack[top]=ch;
	                break;
	        	case ')':                
	                while(stack[top]!='(')
                    {
	                	suffix[suffix_size++]=stack[top--];
	                }
	                top--;
	                break;
	        	case '+':                
                case '-':      
                    while(top!=0&&stack[top]!='(')
                    {
                        suffix[suffix_size++]=stack[top--];
                    }
                    top++;
                    stack[top]=ch;
                    break;

                case '*':                  //判定为乘除号
                case '/':
                    while(stack[top]=='*'||stack[top]=='/')
                    {
                        suffix[suffix_size++]=stack[top--];
                    }
                    top++;
                    stack[top]=ch;
                    break;
                case ' ':break;
	            default:
                        while(ch>='0'&&ch<='9')
                            {   //判定为数字
	                       		suffix[suffix_size++]=ch;
	                       		ch=str[i++];
	                    	}
	                       i--;
                           /* 数字后面添加& */
	                       suffix[suffix_size]='&';suffix_size++;
               }
               ch=str[i];i++;
        }
        while(top!=0)
        {
            suffix[suffix_size]=stack[top];
            suffix_size++;
            top--;
        }
        suffix[suffix_size]='#';

    	printf("\n后缀表达式：",suffix);
        for(int j=0;j<suffix_size;j++)
            printf("%c",suffix[j]);
    calculate(suffix);
}
/*计算后缀表达式的值*/
void calculate(char suffix[size]){                                 
    float stack[size],d;             //作为栈使用
    char ch;
    int t=0,top=0;                  //t为ex下标，top为stack下标
    ch=suffix[t];t++;
    while(ch!='#'){
        switch(ch){
            case '+':
                stack[top-1]=stack[top-1]+stack[top];
                top--;
                break;
            case '-':
                stack[top-1]=stack[top-1]-stack[top];
                top--;
                break;
            case '*':
                stack[top-1]=stack[top-1]*stack[top];
                top--;
                break;
            case '/':
                if(stack[top]!=0)
                {
                    stack[top-1]=stack[top-1]/stack[top];
                }
                else
                {
                    printf("\nerror：除数不可以为0!\n");
                    exit(0);                   //异常退出
                }
                top--;
                break;
                default:
                d=0;
                while(ch>='0'&&ch<='9'){
                    d=10*d+ch-'0';               //将数字字符转化为对应的数值
                    ch=suffix[t++];
                }
                //top++;
                stack[++top]=d;
        }
        ch=suffix[t];t++;
    }
    printf("\n逆波兰式计算结果：%g",stack[top]);
}

int main()
{
	freopen("Polsih.txt","r",stdin);         //文件读取本地文本内容 
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
		transition(i);
	}
    return 0;
}