// #include <cstdio>
// using namespace std;

// struct NODE
// {
//     int next;
//     bool flag;
// } node[100000];

// int main()
// {
//     int first1, first2, num;
//     scanf("%d %d %d", &first1, &first2, &num);
//     char temp;
//     int a, b;
//     for (int i = 0; i < num; i++)
//     {
//         scanf("%d %c %d", &a, &temp, &b);
//         node[a] = {b, false};
//     }
//     for (int i = first1; i != -1; i = node[i].next)
//         node[i].flag = true;

//     for (int i = first2; i != -1; i = node[i].next)
//     {
//         if (node[i].flag == true)
//         {
//             printf("%05d", i);
//             return 0;
//         }
//     }
//     printf("-1");
//     return 0;
// }

#include <iostream>
using namespace std;
//大数组要放在堆中防止段错误
#define M 100000
int list1[M] = {0}, list2[M] = {0}, second[M] = {0};
int main()
{
    int list1_first, list2_first, num;
    cin >> list1_first >> list2_first >> num;


//这个输入问题很大,出现字符要格外注意
char  temp;
    for (int i = 0, first = 0; i < num; i++)
    {
        // scanf("%d %c %d", &first, &temp, &second[first]);//在这个first没有正式赋值之前是不可以直接用的
        scanf("%d ", &first);
        getchar();
        scanf("%d", &second[first]);
    }

    int list1_len = 0, list2_len = 0;
    for (int i = list1_first; i != -1; i = second[i])
        list1[list1_len++] = i;

    for (int i = list2_first; i != -1; i = second[i])
        list2[list2_len++] = i;

    int i = 0, j = 0;
    if (list1_len > list2_len)
        i = list1_len - list2_len;
    else
        j = list2_len - list1_len;

    while (j < list2_len && i < list1_len && (list1[i] != list2[j]))
    {
        i++;
        j++;
    }

    if (i < list1_len && j < list2_len && list1[i] == list2[j])
        printf("%05d", list1[i]);
    else
        printf("-1");

    return 0;
}