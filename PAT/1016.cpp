#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define off 0
#define on 1
using namespace std;

int rate[25]; //费率
struct NODE
{
    string name;                  //客户姓名
    int month, day, minute, hour; //通话时间
    int status;                   //当前通话状态
    int time;                     //将时间化为整数格式
};
bool cmp(NODE a, NODE b) //最巧妙的设计
{
    return (a.name == b.name) ? a.time < b.time : a.name < b.name;
}

double bill(NODE a)
{
    double total = a.minute * rate[a.hour] + a.day * rate[24] * 60; //先求出非整时的费用和直至前天的费用

    for (int i = 0; i < a.hour; i++)
    {
        total += rate[i] * 60;
    }
    return total / 100.00; //cents 美分转换为美元
}
int main()
{
    for (int i = 0; i < 24; i++)
    {
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    int num = 0;
    scanf("%d", &num);
    vector<NODE> data(num);
    for (int i = 0; i < num; i++)
    {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
        string temp;
        cin >> temp;
        data[i].status = (temp == "on-line") ? on : off;
        data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
    }

    sort(data.begin(), data.end(), cmp);

    //开始记录有用的NODE
    map<string, vector<NODE>> result;

    for (int i = 1; i < num; i++)
    {
        if (data[i].name == data[i - 1].name && data[i - 1].status == on && data[i].status == off)
        {
            result[data[i - 1].name].push_back(data[i - 1]);
            result[data[i].name].push_back(data[i]);
        }
    }

    for (auto ind : result)
    {
        vector<NODE> temp = ind.second;

        cout << ind.first;
        printf(" %02d\n", temp[0].month); //全当一个月内的
        double total = 0;
        for (int i = 1; i < temp.size(); i += 2)
        {
            double t = bill(temp[i]) - bill(temp[i - 1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
            total += t;
        }
        printf("Total amount: $%.2lf\n", total);
    }
}