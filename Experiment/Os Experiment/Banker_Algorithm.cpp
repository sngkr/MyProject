#include<iostream>
#include<fstream>

using namespace std;

/*所需变量、数据结构、函数*/

/*变量*/
//定义进程数、资源种数
#define Pro_num 5
#define Rec_num 3
//目前请求的进程
int Req_Pro;

/*数据结构*/
//最大需求矩阵
int Max[Pro_num][Rec_num];
//目前分配矩阵
int Allocate[Pro_num][Rec_num];
//目前需求矩阵
int Need[Pro_num][Rec_num];
//可用资源(A\B\C)
int Avaiable[Rec_num];
//请求矩阵
int Request[Pro_num][Rec_num];
//确定的安全序列
int Safe_list[Pro_num];


/*函数*/
//银行家算法
void Ba_Algo();
//读取txt文件--->Source.txt
void Get_info();
//将结果保存到txt文件--->Result.txt
void Save_info();
//安全算法
int Safe_Algo();

int main()
{
    //1、获取请求资源
    cout<<"请求资源进程序号："<<endl;
    cin>>Req_Pro;

    cout<<"需要的各类资源数：（A、B、C）"<<endl;
    for(int column=0; column<Rec_num; column++)
        cin>>Request[Req_Pro][column];
   
   
    //2、获取所用到的信息
    Get_info();

    //3、银行家算法
    Ba_Algo();

    return 0;
}


void Ba_Algo()
{
    /* 确定是否需要分配资源操作 */
    //请求矩阵 Request
    for(int column=0; column<Rec_num; column++)
    {
        if(Request[Req_Pro][column] > Need[Req_Pro][column])
        {
            cout<<"无法分配"<<endl;
            return ;
        }
        if(Request[Req_Pro][column] > Avaiable[column])
        {
            cout<<"进程P"<<Req_Pro<<"等待"<<endl;
        }
    }

 /* 开始分配资源 */
    for(int column=0; column<Rec_num; column++)
    {
        //求出各还可以分配的数量
        Avaiable[column] -= Request[Req_Pro][column];
        //更新进程P[Req_Pro]的各资源目前分配数
        Allocate[Req_Pro][column] += Request[Req_Pro][column];
        //更新进程P[Req_Pro]的各资源目前需求数
        Need[Req_Pro][column] -= Request[Req_Pro][column];
    }
    //确定目前分配是否安全
    int safe_num=Safe_Algo();

    if(safe_num==Pro_num)
    {
        cout<<"安全序列：";
        for(int row=0; row<Pro_num; row++)
        {
            cout<<Safe_list[row]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"无法分配"<<endl;
    }
}

int Safe_Algo()
{
    int safe=0;
    int Finish[Pro_num]={0};
    for(int row=0; row<Pro_num; row++)
    {
        int column=0;
        if(Finish[row]==0)
        {
            //判断 进程的 if（Need < Avaiable) 
            while(column < Rec_num  && Need[row][column]<=Avaiable[column])
            {
                column++;
            }
            //如果可用资源全部满足
            if(column==Rec_num)
            {
                //更新可用资源的数量
                for( column=0; column<Rec_num; column++)
                {
                    Avaiable[column] += Allocate[row][column];
                }

                //记录分配序列
                Safe_list[safe++]=row;
                //记录，防止重复检查
                Finish[row]=1;
                //重新开始检查
                row = -1;
            }
        }
    }
    int num_safe=0;
    for(int i=0; i<Pro_num; i++)
    {
        if(Finish[i]==1)
        num_safe++;
    }   
    //安全的进程数
    return num_safe;
}
void Get_info()
{
    ifstream infile("Source.txt",ios::in);
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            //行row  列column  ^^
            for(int row=0; row<Pro_num; row++)
            {
                //获取最大需求 Max
                for(int column=0; column<Rec_num; column++)
                  {
                        infile>>Max[row][column];
                        //cout<<Max[row][column]<<" ";
                  }
                //获取已经分配 Allocate
                for(int column=0; column<Rec_num; column++)
                   {
                        infile>>Allocate[row][column];
                        //cout<<Allocate[row][column]<<" ";
                   }
                //获取仍需分配 Need
                for(int column=0; column<Rec_num; column++)
                    {
                        infile>>Need[row][column];
                        //cout<<Need[row][column]<<" ";
                    }
                //获取可用资源
                if(row==0)
                {
                    for(int column=0; column<Rec_num; column++)
                    {
                        infile>>Avaiable[column];
                    }
                }
            }
        }
        //关闭文件
        infile.close();

    }
    else
    {
        cout<<"Get_info() Error!!"<<endl;
    }

}