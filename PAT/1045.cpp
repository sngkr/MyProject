#include <iostream>
#include <vector>

using namespace std;

int book[201], a[10001], dp[10001];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1, tmp; i <= m; i++)
    {
        scanf("%d", &tmp);
        book[tmp] = i;
    }

    int l, num = 0;
    scanf("%d", &l);

    for (int i = 0, temp; i < l; i++)
    {
        scanf("%d", &temp);
        if (book[temp] >= 1)
            a[num++] = book[temp];
    }
    int maxn = 0;
    for (int i = 0; i < num; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);

        maxn = max(dp[i], maxn);
    }

    printf("%d", maxn);
    return 0;
}