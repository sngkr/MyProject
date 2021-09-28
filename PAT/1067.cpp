// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, t, cnt = 0, a[100010];
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> t;
//         a[t] = i;
//     }
//     for (int i = 1; i < n; i++)
//     {
//         if (i != a[i])
//         {
//             while (a[0] != 0)
//             {
//                 swap(a[0], a[a[0]]);
//                 cnt++;
//             }
//             if (i != a[i])
//             {
//                 swap(a[0], a[i]);
//                 cnt++;
//             }
//         }
//     }
//     cout << cnt;
//     return 0;
// }

#include <stdio.h>
int a[100010] = {0};
int b[100010] = {0};
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] != i)
        {
            b[i] = 1; //错位
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 1)
        { //错位环的最低位e
            int ans = a[i];
            b[i] = -1;
            count++;
            while (b[ans] == 1)
            {
                b[ans] = -1;
                ans = a[ans];
                count++;
            }
            count++;
        }
    }
    if (a[0] != 0)
        count -= 2;
    printf("%d", count);
}