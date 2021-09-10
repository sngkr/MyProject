#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#define size 66
/* 函数 */
void calculate(char suffix[size]);
void transition(int pri);
/* 变量 */
char suffix[size];      //存储后缀表达式
char str[size];   	   //存储原算术表达式
char stack[size];       //计算时使用的栈
/*将算术表达式转化为后缀表达式*/
void transition(int pri)
{        

    char ch;
    int sum,i=0,suffix_size=0,top=0;
    printf("\n\n算数表达式：");
    scanf("%s",str);		//获取用户输入的表达式
    printf("%s",str);
    sum=strlen(str);
    	i=0,suffix_size=0;
        ch=str[i];i++;
        while(ch!='#')
        {
            switch(ch)
            {
	            case '(':        //左括号         
	                stack[++top]=ch;
	                break;
	        	case ')':        //右括号       
	                while(stack[top]!='(')
                    {
	                	suffix[suffix_size++]=stack[top--];
	                }
	                top--;
	                break;
	        	case '+':         //加减      
                case '-':      
                    while(top!=0 && stack[top]!='(')//优先级
                    {
                        suffix[suffix_size++]=stack[top--];
                    }
                    stack[++top]=ch;
                    break;

                case '*':      //乘除号
                case '/':
                    while(stack[top]=='*'||stack[top]=='/')
                    {
                        suffix[suffix_size++]=stack[top--];
                    }
                    stack[++top]=ch;
                    break;
                case ' ':
                    break;
	            default:
                    while(ch>='0'&&ch<='9')
                    {   //数字
                        suffix[suffix_size++]=ch;
                        ch=str[i++];
                    }
                    i--;
                    /* 数字后面添加& */
                    suffix[suffix_size++]='&';
            }
            ch=str[i++];
        }
        while(top!=0)
        {
            suffix[suffix_size++]=stack[top--];
        }
        suffix[suffix_size]='#';

    	printf("\n后缀表达式：");
        for(int j=0;j<suffix_size;j++)
            printf("%c",suffix[j]);
            
    calculate(suffix);

}
/*计算后缀表达式的值*/
void calculate(char suffix[size])
{                                 
    float stack[size],d;             //作为栈使用
    char temp;
    int t=0,top=0;                  //t为ex下标，top为stack下标
    temp=suffix[t++];
    while(temp!='#')
    {
        switch(temp)
        {
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
                while(temp>='0'&&temp<='9')
                {
                    d=10*d+temp-'0';               //将数字字符转化为对应的数值
                    temp=suffix[t++];
                }
                //top++;
                stack[++top]=d;
        }
        temp=suffix[t];t++;
    }
    printf("\n逆波兰式计算结果：%g",stack[top]);
}

int main()
{
    printf("编制人：\n姓名：宋可\t学号：116132019141\t班级：计本3班\n");
	freopen("Polsih.txt","r",stdin);         //文件读取
	int n;
	scanf("%d",&n);//先获取表达式的数量
	for(int i=0;i<n;i++)
    {
		transition(i);
	}
    return 0;
}