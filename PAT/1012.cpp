#include <iostream>
#include <algorithm>
using namespace std;

struct NODE
{
    int ID, best;
    int score[4];
    int rank[4];
} a[2001];

int flag = 0;
int Have[1000000] = {0};
bool cmp(NODE a, NODE b)
{
    return a.score[flag] > b.score[flag];
}
int main()
{
    int stu_num, find_num;
    cin >> stu_num >> find_num;
    for (int i = 0; i < stu_num; i++)
    {
        cin >> a[i].ID >> a[i].score[1] >> a[i].score[2] >> a[i].score[3];
        a[i].score[0] = (a[i].score[1] + a[i].score[2] + a[i].score[3]) / 3;

        // Have[a[i].ID] = i + 1;/* 不应该放在这，应该放在排序过后的 */
    }

    //排名
    for (flag = 0; flag < 4; flag++)
    {
        sort(a, a + stu_num, cmp);
        a[0].rank[flag] = 1;

        for (int i = 1; i < stu_num; i++)
        {
            a[i].rank[flag] = i + 1;
            if (a[i].score[flag] == a[i - 1].score[flag])
                a[i].rank[flag] = a[i - 1].rank[flag];
        }
    }

    for (int i = 0; i < stu_num; i++)
    {
        Have[a[i].ID] = i + 1;/* 最终每个学生ID位置确定才可以 */

        a[i].best = 0;

        int min = a[i].rank[0];

        for (int j = 1; j <= 3; j++)
        {
            if (a[i].rank[j] < min)
            {
                min = a[i].rank[j];
                a[i].best = j;
            }
        }
    }

    char c[5] = {'A', 'C', 'M', 'E'};
    for (int i = 0, temp; i < find_num; i++)
    {

        cin >> temp;
        if (Have[temp])
        {
            // cout << Have[temp] << endl;
            int b = a[Have[temp] - 1].best;
            cout << a[Have[temp] - 1].rank[b] << " " << c[b] << endl;
        }
        else
        {
            cout << "N/A" << endl;
        }
    }

    return 0;
}