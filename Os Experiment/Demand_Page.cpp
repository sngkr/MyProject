#include<iostream>
#include<queue>
using namespace std;


const int operation_num = 8;
/* 数据结构 */
typedef struct Pagetable 
{
	int pnum; //页号
	int flag; //状态
	int block; //块号
	int modify; //标志
	int address; //地址
}Page;

/* FIFO/LRU 所用的队列 */
queue<int> q;

/* 记录队列变化 */

int Queue_Change[operation_num][3];

/* 函数 */
bool Serach_page(int pnum);//判断该页是否在内存中
void LRU(int pnum);
void FIFO(int punm);
void Display_Page();//页表信息显示
void Queue_Init();//队列初始化
void Update_Queue_Change();//更新数组Queue_Change
void Display_Queue_Change();//打印数组Queue_Change
void Display_Queue();//打印队列信息


/* 变量 */
Page page[]=
 { 
    {0, 1,  3, 0, -1},
    {1, 1,  4, 0, -1},
    {2, 1,  5, 0, -1},
    {3, 0, -1, 0, 30},
    {4, 0, -1, 0, 25},
    {5, 0, -1, 0, 26}
 };

int intr_num=0;//中断次数
int FIFO_num = 0;//FIFO队列数
long long int oper[]=//玩
{
    4300302003,
    5510502005,
    5220015004,
    5730071031,
};
string study[]=
{
    "(3030H)+(5003H)",
    "(4050H)-(5005H)",
    "(5001H)*(3004H)",
    "(4007H)/(5031H)"
};

/* *****************函数************************* */
/* 函数实现 */

/* 判断该页是否在内存中 */
bool Serach_page(int pnum)
{
    if(page[pnum].flag == 1)
        return true;
    else
        return false;
}

/* 显示页表信息 */
void Display_Page()
{
    for(int i=0; i<6; i++)
    {
        cout << page[i] .pnum << "\t" \
        << page[i] .flag << "\t" \
        << page[i] .block << "\t" \
        << page[i] .modify << "\t" \
        << page[i] .address << "\t" \
        << endl;
    }
}
/* 输出队列 */
void Display_Queue()
{

    for(int i=0; i<3; i++)
    { 
        cout<<q.front()<< " ";
        q.push(q.front());
        q.pop();
    }
    cout<<endl;
}
/* 输出Queue_Change */
void  Display_Queue_Change()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<Queue_Change[i][j]<< " ";
        }
        cout<<endl;
    }
}

/* 初始化队列 FIFO使用 */
void Queue_Init()
{
    for(int i=0; i<3; i++)
        q.push(i);   
    //  update_in_FIFO();
    //  display_queue();
}

/* 记录所有的FIFO队列 */
void Update_Queue_Change()
{
    for(int i=0; i<3; i++)
    {
       Queue_Change[FIFO_num][i] = q.front();
        q.push(q.front());
        q.pop();
    }
    FIFO_num++;
}
void LRU(int pnum)
{
        int page_numa,  //用来记录页号
        page_numb,  //用来记录页号
        time_max;   //用来记录在内存中驻留时间最长的页的页号
    /* 判断该页是否在内存中 */
    if(Serach_page(pnum))
    {
        /* 存在，1、将该页从栈中移出，并压入栈顶，2、更新数组Queue_Change  */
        //  Display_Queue();
        /* 1、将该页从“栈”中移出，并压入“栈顶”， 就用原来的队列，不换其他的了 */
        int a[3];
        int target;
        for(int i=0; i<3; i++)
        {
            if(pnum == q.front())
                target = i;
            a[i] = q.front();
            q.pop();
        }

        for(int i=0; i<3; i++)
        {
            if(i != target)
                q.push(a[i]);
        }
        q.push(a[target]);
        /* 2、更新数组Queue_Change */
        // Display_Queue();
        Update_Queue_Change();
        return ;
    }
    else
    {
    /* 如果没有在内存中，在页表中找到该页，然后放入队尾，刚刚的队头出队 */
    /* 找出在内存中驻留时间最长的页，也就是队头 */
         time_max = q.front();
    /* 确定页号 */
        for(int i=0; i<6; i++)
        {
            if(page[i].pnum == time_max)
            {
                page_numa = i;
                break;
            }
        }
    /* 确定页号 */
        for(int i=0; i<6; i++)
        {
            if(page[i].pnum == pnum)
            {
                page_numb = i;
                break;
            }
        }
        /* 更新总表 */
        /* 将队首所对应的页释放，同时将队尾所对应的页收押 */
        page[page_numa].flag = 0;
        page[page_numb].flag = 1;

        /* 将原来队首的信息写入现在的队尾，并更新队首的信息 */
        page[page_numa].address = page[page_numb].address;
        page[page_numb].address = -1;
        page[page_numb].block = page[page_numa].block;
        page[page_numa].block = -1;

        /* 更新队列 */
        q.pop();
        q.push(pnum);
        // display_queue();
        /* 更新数组Queue_Change  */
        Update_Queue_Change();

        cout<<"第 "<< ++intr_num <<" 次缺页"<<endl;
        /* 显示总表信息 */
        Display_Page();
    }
}

/* FIFO */
void FIFO(int pnum)
{
    int page_numa,  //用来记录页号
        page_numb,  //用来记录页号
        time_max;   //用来记录在内存中驻留时间最长的页的页号
    /* 判断该页是否在内存中 */
    if(Serach_page(pnum))
    {
        /* 存在，更新数组Queue_Change  */
        // display_queue();
        Update_Queue_Change();
        return ;
    }
    else
    {
    /* 如果没有在内存中，在页表中找到该页，然后放入队尾，刚刚的队头出队 */
    /* 找出在内存中驻留时间最长的页，也就是队头 */
         time_max = q.front();
    /* 确定页号 */
        for(int i=0; i<6; i++)
        {
            if(page[i].pnum == time_max)
            {
                page_numa = i;
                break;
            }
        }
    /* 确定页号 */
        for(int i=0; i<6; i++)
        {
            if(page[i].pnum == pnum)
            {
                page_numb = i;
                break;
            }
        }
        /* 更新总表 */
        /* 将队首所对应的页释放，同时将队尾所对应的页收押 */
        page[page_numa].flag = 0;
        page[page_numb].flag = 1;

        /* 将原来队首的信息写入现在的队尾，并更新队首的信息 */
        page[page_numa].address = page[page_numb].address;
        page[page_numb].address = -1;
        page[page_numb].block = page[page_numa].block;
        page[page_numa].block = -1;

        /* 更新队列 */
        q.pop();
        q.push(pnum);
        // display_queue();
        /* 更新数组Queue_Change  */
       Update_Queue_Change();

        cout<<"第 "<< ++intr_num <<" 次缺页"<<endl;
        /* 显示总表信息 */
        Display_Page();
    }
}

int main()
{
    Queue_Init();
    for(int i=0; i<4; i++)
    {
        // 稍稍微微留点通过移位获得指令内容的味道
        char  operate = (char)(oper[i]/100000000);
        int page_a = (int)((oper[i]/10000000)%10);
        int page_b = (int)((oper[i]/1000)%10);

        // cout<<"操作:  "<< i << " 懂得……懂得"<<endl;
        cout<< "操作："<< i << " " << study[i] <<endl;
        // FIFO(page_a);
        // FIFO(page_b);
        LRU(page_a);
        LRU(page_b);
    }
    // cout<<"FIFO 队列"<<endl;
        cout<<"LRU 队列"<<endl;
        /* 输出LRU/FIFO 队列 */
    Display_Queue_Change();

    return 0;
}