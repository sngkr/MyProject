// /**
//  * 操作系统课程设计
//  * 题目：11.银行家算法
//  * 输入请求资源，判断安全状态;
//  * 打印资源分配表
//  * 作者：bruce·ling
//  * 版本：3.0 （2016.12.20）
//  */
// #include <iostream>
// #include <fstream>

// #define PROGRESS 5     //进程数量
// #define REC_NUM  3     //资源种类数量

// using namespace std;

// //定义数据结构
// int Available[PROGRESS];      //定义可用资源向量Available
// int sign[PROGRESS],work[PROGRESS][REC_NUM],workAll[PROGRESS][REC_NUM];
//         //记录成功的安全序列,并定义工作矩阵和可用资源矩阵
// int Max[PROGRESS][REC_NUM],Allocation[PROGRESS][REC_NUM],Need[PROGRESS][REC_NUM];
//         //定义最大需求矩阵Max，分配矩阵Allocation，需求矩阵Need

// void Read_file();     //读取文件
// int Banker_Algorithm(int,int [][REC_NUM]);       //银行家算法
// int Safe_Algorithm(int [],int [][REC_NUM],int [][REC_NUM]);    //安全性算法
// void Print_Run_Order(int);         //打印判断执行序列

// int main()
// {
//         //读取文件数据并打印,然后将数据存入到相应矩阵中
//         Read_file();

//          //任务开始
//         int i,N=0;    // 'N'表示请求资源次数
//         int Request[PROGRESS][REC_NUM];  //定义请求矩阵Requset

//         while(N!=999) {
//                 cout<<endl<<"请输入请求资源Request[进程标号i][资源类型j]:"<<endl;
//                 cout<<"进程i = ";
//                 cin>>i;
//                 cout<<"各类资源数量(A B C) =  ";
//                 for(int m = 0;m < REC_NUM;m++)  
//                         cin>>Request[i][m];
//                 cout<<endl;
//                 //执行银行家算法
//                 int result = Banker_Algorithm(i,Request);
//                 //输出每次判断产生的执行序列
//                 cout<<endl<<"资源分配表："<<endl;
//                 Print_Run_Order(result);

//                 cout<<endl<<"请输入N(当N=999退出)："<<endl;
//                 cin>>N;
//         }
// }
// //读取文件数据，打印到控制台，并将数据存入到相应矩阵中
// void Read_file(){
//         //读取完整文件并打印
//         ifstream inFile1("Alldata.txt",ios::in);  //创建文件流对象
//         if(!inFile1)      //判断对象inFile打开文件成功与否
//               cerr<<"File open error."<<endl;  //使用错误流对象输出错误信息
//         else {
//                 char c;
//                 while((c=inFile1.get())!=EOF)  //按字符读取文件内容，到达末尾停止
//                         cout<<c;
//                 cout<<endl;
//                 inFile1.close();
//         }
//         //读取只有数字的文件并存入矩阵中
//         ifstream inFile2("data.txt",ios::in);
//         if(!inFile2)
//               cerr<<"File open error."<<endl;
//         else{
//                 int data;
//                //读取数字并存入矩阵
//                 for(int j = 0;j < PROGRESS;j++) {
//                 for(int i = 0;i < REC_NUM;i++) {
//                     inFile2>>data;
//                     Max[j][i]=data;
//                 }
//                 for(int i = 0;i < REC_NUM;i++) {
//                     inFile2>>data;
//                     Allocation[j][i]=data;
//                 }
//                 for(int i = 0;i < REC_NUM;i++) {
//                     inFile2>>data;
//                     Need[j][i]=data;
//                 }
//                 if(j==0) {
//                     for(int i = 0;i < REC_NUM;i++) {
//                         inFile2>>data;
//                         Available[i]=data;
//                     }
//                 }
//                }
//                 inFile2.close();
//         }
// }
// //银行家算法
// int Banker_Algorithm (int i,int Request[][REC_NUM]){
//         for(int m = 0;m < REC_NUM;m++) {
//                 if(Request[i][m] > Need[i][m]){
//                         cout<<"所需资源数超出其宣布的最大值!"<<endl;
//                         return 0;
//                 } else if(Request[i][m] > Available[m]) {
//                         cout<<"无足够资源，p["<<i<<"]需等待!"<<endl;
//                         return 0;
//                 }
//         }
//         //尝试为进程分配资源
//         for(int j = 0;j < REC_NUM;j++) {
//                 Available[j] = Available[j] - Request[i][j];
//                 Allocation[i][j] = Allocation[i][j] + Request[i][j];
//                 Need[i][j] = Need[i][j] - Request[i][j];
//         }
//         //执行安全性算法
//         int n = Safe_Algorithm(Available,Need,Allocation);
//         cout<<endl;

//         if(n == PROGRESS) {//有5个'true'返回1，表示此时刻安全
//                 cout<<"此时刻是安全状态，可以分配资源给"<<"P["<<i<<"]!"<<endl;
//         }else {
//                 cout<<"此时刻不是安全状态，不能将资源分配给"<<"P["<<i<<"]!"<<endl;
//         }
//         return n;
// }
// //安全性算法
// int Safe_Algorithm(int Available[],int Need[][REC_NUM],int Allocation[][REC_NUM]) {
//         int i=0,j=0,m=0,n=0;
//         int Work[REC_NUM],Finish[PROGRESS] = {0,0,0,0,0};
//         for(int r = 0;r < REC_NUM;r++) //将可用资源数目赋给工作向量Work
//                 Work[r] = Available[r];
//         while(i < PROGRESS) {
//                 if(Finish[i] == 0){
//                         //满足条件释放资源，并从头开始扫描进程集合
//                         while(j < REC_NUM && Need[i][j] <= Work[j] )
//                                 j++;
//                         if(j == REC_NUM) {
//                                 for(int k = 0;k < REC_NUM;k++){
//                                         work[i][k] = Work[k];
//                                         Work[k] = Work[k]+Allocation[i][k];
//                                         workAll[i][k] = Work[k];
//                                 }
//                                 Finish[i]=1;
//                                 sign[m]=i;  //保存安全序列
//                                 i=-1;m++;
//                         }
//                 }
//                 j=0;i++;
//         }
//         for(int p = 0;p < PROGRESS;p++){
//                if(Finish[p] == 1)
//                         n++;   //记录'true'个数
//         }
//         return n;     //返回'true'个数
// }
// //打印安全性检查的执行序列
// void Print_Run_Order(int result) {
//         if(result == PROGRESS) {
//                 cout<<" 进程\\资源情况"<<" Work(A B C)"<<" Need(A B C)"
//                     <<" Allocation(A B C)"<<" Work+Available(A B C)"<<" Finish";
//                 cout<<endl;
//                 for(int i = 0;i < PROGRESS;i++) {
//                         cout<<"    "<<"P["<<sign[i]<<"]  "<<'\t';
//                         for(int j = 0;j < REC_NUM;j++)
//                                cout<<work[sign[i]][j]<<" ";
//                         cout<<'\t'<<'\t';
//                         for(int j = 0;j < REC_NUM;j++)
//                                cout<<Need[sign[i]][j]<<" ";
//                         cout<<'\t'<<'\t';
//                         for(int j = 0;j < REC_NUM;j++)
//                                cout<<Allocation[sign[i]][j]<<" ";
//                         cout<<'\t'<<'\t';
//                         for(int j = 0;j < REC_NUM;j++)
//                                cout<<workAll[sign[i]][j]<<" ";
//                         cout<<'\t'<<'\t';
//                         cout<<"true"<<endl;
//                 }
//                 cout<<endl<<"找到安全序列｛P["<<sign[0]<<"]";
//                 for(int m = 1;m < PROGRESS;m++){
//                         cout<<", P["<<sign[m]<<"]";
//                 }
//                 cout<<"}"<<endl;

//         } else {
//                 cout<<"   进程\\资源情况 "<<"  Allocation(A B C)"<<"   Need(A B C)"<<"   Available(A B C)";
//                 cout<<endl;
//                 for(int k = 0;k < 5;k++){
//                         cout<<'\t'<<"P["<<k<<"]"<<'\t'<<'\t';
//                         for(int j = 0;j < 3;j++)
//                                 cout<<Allocation[k][j]<<" ";
//                         cout<<'\t'<<'\t';
//                         for(int j = 0;j < 3;j++)
//                                 cout<<Need[k][j]<<" ";
//                         cout<<'\t'<<'\t';
//                         if(k == 0) {
//                                 for(int j = 0;j < 3;j++)
//                                 cout<<Available[j]<<" ";
//                         }
//                         cout<<endl;
//                 }
//         }
// }


#include <stdio.h>
#include <stdlib.h>

#define MIN_SLICE 2            //最小碎片大小
#define DEFAULT_MEM_SIZE 1024   //内存大小
#define DEFAULT_MEM_START 0     //起始位置


typedef struct freearea        //空闲分区结点
{
	int startaddress;   //起始地址
	int size;            //空闲块的大小
	struct freearea *next;      //指向下一个空闲块
}Block;

Block * get_space()    //初始化存储区，得到一个带头结点的链表
{
	Block * space = (Block*)malloc(sizeof(Block));
	Block *node = (Block*)malloc(sizeof(Block));
	node->startaddress = DEFAULT_MEM_START;
	node->size = DEFAULT_MEM_SIZE;
	node->next = NULL;
	space->next = node;
	return space;
}


void destroy_space(Block *Head)  //清空链表
{
	Block *node = Head->next;
	while (node)
	{
		Head->next = node->next;
		free(node);
		node = Head->next;
	}
	free(Head);
}

/////////////////////////////////////////////////////////////////////////////////////////
int alloc(Block *Head, int applyarea)  //申请空间
{

	if (applyarea > DEFAULT_MEM_SIZE)
	{
		printf("申请的空间大于内存空间，失败！\n");
		return -1;
	}

	Block *prior = Head;     //前一个结点
	Block *node = Head->next;
	/*
	只要链表中的结点没有搜索完
		取一个结点，判断该结点是否可分配
		情况1，结点空间大于申请量，但分配后的空间小于指定最小碎片大小，不分配；
		情况2，结点空间正好等于申请量，把该结点从空闲分区链表中删除并分配给该空间，返回分配的首地址；
		其他情况，无法分配；
		查看下一个结点
	所有结点都不满足分配条件
		输出提示语句，返回-2
	*/
        return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

int do_alloc(Block *Head)  //申请空间操作
{
	int applyarea;
	printf("需要申请多大的空间：");
	scanf("%d", &applyarea);

	return alloc(Head,applyarea);

}
/////////////////////////////////////////////////////////////////////////////
int setfree(Block *Head, int start, int len)     //回收存储空间
{
	Block *prior, *next;
	prior = Head;
	next = prior->next;
	if (start < 0 || len <= 0)
	{
		printf("输入的开始位置或长度过小,开始位置应大于等于0，长度应大于0\n");
		return -1;
	}
	if (start >= DEFAULT_MEM_SIZE || len >DEFAULT_MEM_SIZE)
	{
		printf("输入的开始位置或长度过大,开始位置应小于%d，长度应小于等于%d\n"
			, DEFAULT_MEM_SIZE, DEFAULT_MEM_SIZE);
		return -2;
	}
	while (1)
	{
		if (next->startaddress >= start + len || next == NULL)    //next是回收处的后一个空闲块
			break;
		prior = next;
		next = next->next;
	}
	int condition = 0;   //与前后空间链接情况，0表示与前后都不连接，1表示与前面合并，2表示与后面合并，3表示前后都要合并
	if (prior != Head)  //回收的不是第一个空闲块的更前面
	{
		if (prior->startaddress + prior->size > start) //回收区域跨过了空闲块
		{
			printf("回收的空间跨越了空闲块\n");
			return -3;
		}
		if (prior->startaddress + prior->size == start)  //与前面空闲块相连接
			condition = condition + 1;
	}

	if (next != NULL)  //回收的不是最后一个空闲块的后面
	{
		if (next->startaddress == start + len)  //与后面空闲块相连接
			condition = condition + 2;
	}
	/*4种情况回收空间的方法，
	
	
	
	参见P129*/

        return  0;
}

int do_setfree(Block *Head)     //回收存储空间
{
	int start, len;
	printf("输入回收空间的开始位置：");
	scanf("%d", &start);
	printf("输入回收空间的大小：");
	scanf("%d", &len);
	return setfree(Head, start, len);
}


void output(Block *Head)
{
	int has_out = 0;  //已经输出的空间大小
	char used[] = "已分配";
	char un_used[] = "未分配";
	printf("*************************************************************\n");
	printf("当前内存的使用情况为：\n");
	printf("起始地址\t大小\t状态\n");
	Block *node, *tmp;
	node = Head->next;
	if (node != NULL && node->startaddress > DEFAULT_MEM_START)   //第一个结点前后已经分配的空间
	{
		printf("%4d\t\t%4d\t%s\n", DEFAULT_MEM_START, node->startaddress, used);
		has_out += node->startaddress;   //做记录
	}

	while (node)
	{
		if (node->startaddress > has_out)
		{
			printf("%4d\t\t%4d\t%s\n", has_out, node->startaddress - has_out, used);
			has_out = node->startaddress;   //做记录
		}

		printf("%4d\t\t%4d\t%s\n", node->startaddress, node->size, un_used);
		has_out += node->size;   //做记录
		//下一个结点
		tmp = node;
		node = node->next;
		//中间可能有已分配的结点
	}
	if (has_out < DEFAULT_MEM_START)//还没有输出完成
	{
		printf("%4d\t\t%4d\t%s\n", has_out, DEFAULT_MEM_START - has_out, used);
	}
}

int main()
{
	char command;
	Block *memory = get_space();
	while(1)
	{
		output(memory);
		printf("\n需要做的操作是：申请（a),释放（f),退出（z)，清屏(c)\n");
		command = getchar();
		if (command == 'z' || command == 'Z')
			break;
		else if (command == 'a' || command == 'A')
			do_alloc(memory);
		else if (command == 'f' || command == 'F')
			do_setfree(memory);
		else if (command == 'c' || command == 'C')
			system("cls");
		getchar();
	}
	destroy_space(memory);
	system("pause");
	return 0;
}

