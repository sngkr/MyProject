// #include <cstdio>
// #include <algorithm>
// using namespace std;
// #define M 1000000
// int couple[M], single[M], part[M];
// int main()
// {
//     int num;
//     scanf("%d", &num);
//     for (int i = 0, a, b; i < num; i++)
//     {
//         scanf("%d %d", &a, &b);
//         couple[a] = b;
//         couple[b] = a;
//     }

//     scanf("%d", &num);
//     for (int i = 0; i < num; i++)
//     {
//         scanf("%d", &part[i]);
//     }

//     int count = 0; //单身数
//     for (int i = 0; i < num; i++)
//     {
//         int maybe = part[i];
//         bool damn = true;
//         for (int j = 0; j < num; j++)
//         {
//             if (couple[maybe] == part[j]) //如果part成员后面有配偶则不为单身
//                 damn = false;
//         }

//         if (damn == true) //如果是单身
//         {
//             single[count++] = maybe; //单身确实
//         }
//     }

//     sort(single, single + count);
//     printf("%d\n", count);

//     for(int i=0; i<count; i++)
//     {
//         if(i != 0)
//             printf(" ");
//         printf("%05d", single[i]);
//     }

//     return 0;
// }

#include <cstdio>
#include <algorithm>
using namespace std;
#define M 1000000
int couple[M], single[M], part[M];
bool inparty[M];
int main()
{
    fill(couple, couple + M, -1);
    fill(inparty, inparty + M, false);

    int num;
    scanf("%d", &num);
    for (int i = 0, a, b; i < num; i++)
    {
        scanf("%d %d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }

    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &part[i]);
        inparty[part[i]] = true;
    }

    int count = 0; //单身数

    for (int i = 0, maybe; i < num; i++)
    {
        maybe = part[i];
        if (couple[maybe] == -1 || !inparty[couple[maybe]])
        {
            single[count++] = maybe;
        }
    }

    sort(single, single + count);
    printf("%d\n", count);

    for (int i = 0; i < count; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%05d", single[i]);
    }

    return 0;
}
