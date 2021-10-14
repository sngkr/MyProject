#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father;
vector<int> Root;
int cluster[1001];

int find_father(int a)
{
    if (father[a] == a)
        return a;
    else
        return find_father(father[a]);
}

void merge(int a, int b)
{
    father[find_father(a)] = find_father(b);
}
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    scanf("%d", &N);
    father.resize(N + 1);
    Root.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        father[i] = i;
    }

    for (int i = 1, num; i <= N; i++)
    {
        scanf("%d:", &num);
        for (int j = 0, temp; j < num; j++)
        {
            scanf("%d", &temp);
            if (cluster[temp] == 0)
                cluster[temp] = i;
            merge(i, find_father(cluster[temp]));
        }
    }

    for (int i = 1; i <= N; i++)
    {
        Root[find_father(i)]++;
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        if (Root[i] != 0)
            cnt++;
    }
    sort(Root.begin(), Root.end(), cmp);

    printf("%d\n", cnt );
    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
            printf(" ");
        cout << Root[i];
    }
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// // vector<unordered_map<int, bool>> cluster;
// int hobby[1005];
// int cluster[1005];
// int cluster_num = 1;
// int sum = 1;

// bool cmp(int a, int b)
// {
//     return a > b;
// }
// int main()
// {
//     int N;
//     scanf("%d", &N);
//     for (int i = 0, num; i < N; i++)
//     {
//         scanf("%d:", &num);
//         // int temp[1005] = {-1};
//         vector<int> temp(num);
//         int flag = -1;
//         for (int j = 0; j < num; j++)
//             cin >> temp[j];

//         /* 如果当前这个人的某个爱好存在某一族， 找出来那一族o */
//         for (int j = 0; j < num; j++)
//         {
//             /* 找到那一族 */
//             if (hobby[temp[j]] != 0)
//                 flag = hobby[temp[j]];
//         }
//         /* 如果有个爱好出现 */
//         if (flag != -1)
//         {
//             /* 将这个人的所有爱好都分为这一族o */
//             for (int j = 0; j < num; j++)
//             {
//                 hobby[temp[j]] = flag;
//             }
//             /* 增加族o的数量 */
//             cluster[flag]++;
//         }
//         /* 否则 */
//         else
//         {
//             /* 否则设立新的族 */
//             for (int j = 0; j < num; j++)
//             {
//                 hobby[temp[j]] = cluster_num;
//             }
//             cluster[cluster_num]++;
//             cluster_num++;
//             sum++;
//         }
//     }

//     printf("%d\n", sum - 1);
//     sort(cluster + 1, cluster + sum, cmp);

//     for (int i = 1; i < sum; i++)
//     {
//         if (i != 1)
//             printf(" ");
//         printf("%d", cluster[i]);
//     }
//     return 0;
// }