// #include <iostream>
// #include <map>
// using namespace std;

// struct NODE
// {
//     int addr, data, next;
//     bool flag;
// } node[100000];

// map<int, bool> judge;
// int list1[100000], list2[100000];
// int main()
// {
//     int begin = 0, num = 0;
//     scanf("%d %d", &begin, &num);

//     for (int i = 0, a = 0, b = 0, c = 0; i < num; i++)
//     {
//         scanf("%d %d %d", &a, &b, &c);
//         node[a] = {a, b, c};
//         b = abs(b);
//         judge.insert({b, false});
//     }
//     int len1 = 0, len2 = 0;
//     for (int i = begin; i != -1; i = node[i].next)
//     {
//         int tep = abs(node[i].data);
//         if (judge[tep] == false)
//         {
//             judge[tep] = true;
//             list1[len1++] = node[i].addr;
//         }
//         else
//         {
//             list2[len2++] = node[i].addr;
//         }
//     }

//     for (int i = 0; i < len1; i++)
//     {

//         if (i == len1 - 1)
//             printf("%05d %d -1\n", list1[len1 - 1], node[list1[len1 - 1]].data, list1[len1 - 1]);
//         else
//             printf("%05d %d %05d\n", list1[i], node[list1[i]].data, list1[i + 1]);
//     }

//     for (int i = 0; i < len2; i++)
//     {
//         if (i == len2 - 1)
//             printf("%05d %d -1\n", list2[len2 - 1], node[list2[len2 - 1]].data, list2[len2 - 1]);
//         else
//             printf("%05d %d %05d\n", list2[i], node[list2[i]].data, list2[i + 1]);
//     }

//     return 0;
// }

#include <iostream>
#include <algorithm>
#define maxn 100000
using namespace std;

struct NODE
{
    int addr, data, next, num = 2 * maxn;
} node[100000];

bool exited[maxn];
int cmp(NODE a, NODE b)
{
    return a.num < b.num;
}
int main()
{
    int begin, num;
    scanf("%d %d", &begin, &num);

    for (int i = 0, a, b, c; i < num; i++)
    {
        scanf("%d", &a);
        scanf("%d %d", &node[a].data, &node[a].next);
        node[a].addr = a;
        b = abs(node[a].data);
        exited[b] = false;
    }
    int len1 = 0, len2 = 0;
    for (int i = begin; i != -1; i = node[i].next)
    {
        if (exited[abs(node[i].data)] == false)
        {
            node[i].num = len1;
            len1++;
            exited[abs(node[i].data)] = true;
        }
        else
        {
            node[i].num = maxn + len2;
            len2++;
        }
    }

    sort(node, node + maxn, cmp);

    for (int i = 0; i < len1 + len2; i++)
    {
        if (i != (len1 - 1) && i != (len1 + len2 - 1))
            printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i + 1].addr);
        else
            printf("%05d %d -1\n", node[i].addr, node[i].data);
    }

    return 0;
}
