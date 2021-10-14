#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
    int arriveTime = 0;
    int prcessing_time = 0;
} lj[10001];
int num = 0;

bool cmp(NODE a, NODE b)
{
    return a.arriveTime < b.arriveTime;
}

int main()
{
    int N, K;
    int arrive = 0;
    int total = 0;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        int hour, minute, second, processing_time;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &processing_time);

        arrive = hour * 3600 + minute * 60 + second;
        if (arrive > 61200)
            continue;

        lj[++num].arriveTime = arrive;
        lj[num].prcessing_time = processing_time * 60;
    }

    sort(lj + 1, lj + 1 + num, cmp);
    priority_queue<int, vector<int>, greater<int>> q;

    /*put K windows in*/
    for (int i = 1; i <= K; i++)
        q.push(28800);

    for (int i = 1; i <= num; i++)
    {
        /* 如果有窗口是空的，那么到达的时间就是开始服务的时间 */
        /* if any windows are empty, the arrive time is the start time of service */
        if (q.top() <= lj[i].arriveTime)
        {
            q.push(lj[i].arriveTime + lj[i].prcessing_time);
            q.pop();
        }
        else
        {
            /* 产生了等待，计算等待时长 */
            /* A wait is generated and wait duration is calculated */
            total += q.top() - lj[i].arriveTime;
            /* 若是产生了等待，那么就窗口服务完的时间就是开始服务的时间 */
            /* A wait is generated , the endtime of window is the start time of service */
            q.push(q.top() + lj[i].prcessing_time);

            q.pop();
        }
    }

    (!num) ? printf("0.0\n") : printf("%.1lf", ((double)total / 60.0) / (double)num);

    return 0;
}