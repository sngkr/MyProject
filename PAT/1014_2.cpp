#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct NODE
{
    int poptime, endtime;
    queue<int> q;
};

int main()
{
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    vector<int> time(K + 1);

    for (int i = 1; i <= K; i++)
        cin >> time[i];

    vector<NODE> window(K + 1);
    vector<int> result(K + 1);
    vector<bool> sorry(K + 1, false);

    /* index = 人序列 */
    int index = 1;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (index <= K)
            {
                window[j].q.push(time[index]);
                if (window[j].endtime >= 540) /* 这里默认了没赋值之前node结构体元素初始化为0 */
                    sorry[index] = true;

                window[j].endtime += time[index];
                if (i == 1)
                    window[j].poptime = window[j].endtime;

                result[index] = window[j].endtime;
                index++;
            }
        }
    }

    while (index <= K)
    {
        /* 假设第一个窗口poptime最小 */
        int min_pop = window[1].poptime;
        /* 并当前最小poptime的窗口为1 */
        int min_win = 1;

        /* 遍历每一窗口 */
        for (int i = 2; i <= N; i++)
        {
            if (window[i].poptime < min_pop)
            {
                min_pop = window[i].poptime;
                min_win = i;
            }
        }

        /*已经确定好窗口以后那么该窗口就要新进顾客了 */
        window[min_win].q.pop();

        window[min_win].q.push(time[index]);

        /* 此时该窗口的poptime 和 endtime、顾客的sorry 和result  已经发生了变化，下面进行更新操作 */
        /* 注意这个判断为什么放在这 */
        if (window[min_win].endtime >= 540)
            sorry[index] = true;
        window[min_win].poptime += window[min_win].q.front();
        window[min_win].endtime += time[index];
        /* 这里注意到，不管怎么样都计算出了没有上班时间限制的服务完成时间 */
        /* sorry 中已经保存了哪些顾客可以被服务完 */
        /* 减少不必要的交错，妙 */
        result[index] = window[min_win].endtime;

        index++;
    }

    for (int i = 1, people = 0, minute = 0; i <= Q; i++)
    {
        cin >> people;
        if (sorry[people] == true)
        {
            cout << "Sorry" << endl;
            continue;
        }
        minute = result[people] + 480;
        printf("%02d:%02d\n", minute / 60, minute % 60);
    }

    return 0;
}
