#include<iostream>
#include<string>
using namespace std;


/*数据结构*/
//分析栈
char A[20];
//剩余串
char B[20];
//终结符
char v1[10]={'i','+','*','(',')','#'};
//非终结符
char v2[10]={'E','G','T','S','F'};


int j=0,b=0,top=0,length;

typedef struct type
{
	char origin;//大写字母
	string  array;//产生式右边字符
	int length;//字符个数
}type;



type e,t,g,g1,s,s1,f,f1;
type C[10][10];

void print()//输出分析栈
{
	for(int a=0; a<=top+1; a++)
		cout<<A[a];
	cout<<"\t\t";
}

void print1()//输出剩余字符串
{
	for(int j=0; j<b; j++)
		cout<<" ";
	for(int j=b; j<=length; j++)
		cout<<B[j];

	cout<<"\t";
}

void  Init_Grammer()
{
		//把文法产生式赋值给结构体

	e.origin = 'E';
	e.array = "TG";
	e.length = 2;

	t.origin = 'T';
	t.array = "FS";
	t.length = 2;

	g.origin = 'G';
	g.array = "+TG";
	g.length = 3;

	g1.origin = 'G';
	g1.array = "^";
	g1.length = 1;

	s.origin = 'S';
	s.array = "*FS";
	s.length = 3;

	s1.origin = 'S';
	s1.array = "^";
	s1.length = 1;

	f.origin = 'F';
	f.array = "(E)";
	f.length = 3;

	f1.origin = 'F';
	f1.array = "i";
	f1.length = 1;
}

//填充分析表
void Init_Table()
{
	for(int m=0; m<5; m++)
		for(int n=0; n<=5; n++)
			C[m][n].origin = 'N';

	C[0][0]=e, C[0][3]=e;
	C[1][1]=g, C[1][4]=g1, C[1][5]=g1 ;
	C[2][0]=t, C[2][3]=t;
	C[3][1]=s1, C[3][2]=s, C[3][4]=C[3][5]=s1;
	C[4][0]=f1, C[4][3]=f;
}
int main()
{
	int m,n,flag=0,finish=0;
	char ch ,x;
	type cha;

	Init_Grammer();
	Init_Table();
	cout<<"编制人：\n"<<"姓名：宋可\t学号：116132019141\t班级：计本3班"<<endl;
	cout<<" input::"<<endl;

	do
	{
		cin>>ch;
		B[j]=ch;
		j++;
	} while (ch!='#');
	length = j;
	//分析当前字符串
	ch=B[0];
	A[top]='#';
	A[++top]='E';

	cout<<"步骤\t\t分析栈\t\t剩余输入串\t\t所用产生式 "<<endl;

	int step=1;
	do
	{
		/* code */
		x=A[top--];
		cout<<step++<<"\t\t";

		//判断是否为终结符
		for(j=0; j<6; j++)
			if(x==v1[j])
			{
				flag=1;
				break;
			}

		//如果为终结符
		if(flag==1)
			{
				if(x=='#')
				{
					finish = 1;
					cout<<"\t\t接受"<<endl;
					return 0;
				}

				if(x==ch)
				{
					print();
					print1();
					cout<<"\t\t"<<ch<<"匹配"<<endl;
					ch=B[++b];//下一个输入字符
					flag=0;
				}
				else
				{
					print();
					print1();
					cout<<"\t\t"<<ch <<"出错"<<endl;
					return 0;
				}
			}
		//如果为非终结符
		else
			{
				for(j=0; j<5; j++)
				{
					if((x==v2[j]))
					{
						m=j;//行号
						break;
					}
				}
				for(j=0; j<6; j++)
				{
					if(ch==v1[j])
					{
						n=j;//列号
						break;
					}
				}
				cha = C[m][n];
				if(cha.origin != 'N')
				{
					print();
					print1();
					cout<<"\t\t"<<cha.origin <<"->";
					cout<<cha.array<<endl;
				//逆序进栈
					for(j = (cha.length-1); j>=0; j--)
					{
							A[++top] = cha.array[j];
					}	

					if(A[top]=='^')
						top--;
				}
				else
				{
					if(ch=='#')
					{
						print();
						print1();
						cout<<"\t\t"<<"接受"<<endl;		
						return 0;				
					}
					else
					{
						print();
						print1();
						cout<<"\t\t"<<x<<"出错"<<endl;
						return  0;
					}
				}
			}
	} while (finish ==0);
	

}