#include <iostream>
#include <algorithm>
#include <string>
#define MAXN 1005

using namespace std;
int father[MAXN], cluster[MAXN], Num[MAXN], Result[MAXN];

// bool cmp(int a, int b)
// {
//     return a < b;
// }
void init()
{
    for (int i = 0; i < MAXN; i++)
        father[i] = i;
}
int find(int x)
{
    return (father[x] == x) ? x : (father[x] = find(father[x]));
}

void merge(int x, int y)
{
    father[find(x)] = find(y);
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0, m1, m2, w, temp; i < N; i++)
    {
        scanf("%d %d %d", &m1, &m2, &w);
        merge(m1, m2);
        temp = find(m2);
        cluster[temp] += w;
        Num[temp]++;
    }
    int cnt = 0;
    for (int i = 0; i < MAXN; i++)
    {
        if (cluster[i] > K)
        {
            Result[cnt++] = i;
        }
    }
    sort(Result, Result+cnt);
    for(int i=0; i<cnt; i++)
    {
        string a = to_string(Result[i]);
        printf("%s %d\n",a.c_str(), Num[Result[i]]);
    }
    return 0;
}