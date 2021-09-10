#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 500

struct NUM
{
    int data;
    bool flag;
} data[maxn];

int min[maxn], max[maxn];

int findmin(NUM d[], int len)
{
    int min = 100005;
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (d[i].data < min && d[i].flag == false)
        {
            min = d[i].data;
            index = i;
        }
    }
    d[index].flag = true;
    return min;
}

int findmax(NUM d[], int len)
{
    int max = -10005;
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (d[i].data > max && d[i].flag == false)
        {
            max = d[i].data;
            index = i;
        }
    }
    d[index].flag = true;
    return max;
}

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 0, temp = 0; i < num; i++)
    {
        scanf("%d", &temp);
        for (int j = 0, d = 0; j < temp; j++)
        {
            scanf("%d", &d);
            data[j] = {d, false};
        }
        int len = temp / 2;
        for (int k = 0; k < len; k++)
        {
            int min_num = findmin(data, temp);
            int max_num = findmax(data, temp);
            min[k] = min_num;
            max[len - k - 1] = max_num;
        }

        for (int l = 0; l < len; l++)
        {
            printf("%d ", min[l]);
        }
        printf("\n");
        for (int l = 0; l < len; l++)
        {
            printf("%d ", max[l]);
        }
        printf("\n");
    }
    return 0;
}

// void bucket_sort(int a[], int len, int max)
// {
//     int i, j;
//     int *buckets;

//     if (a == NULL || len < 1 || max < 1)
//         return;

//     if ((buckets = (int *)malloc(max * sizeof(int))) == NULL)
//         return;

//     memset(buckets, 0, max * sizeof(int));

//     //计数
//     for (i = 0; i < len; i++)
//         buckets[a[i]]++;

//     //排序
//     for (i = 0, j = 0; i < max; i++)
//     {
//         while ((buckets[i]--) > 0)
//             a[j++] = i;
//     }
//     //free(buckets);
// }
// int find(const int a[], int len)
// {
//     int max = -2222;

//     for (int i = 0; i < len; i++)
//     {
//         if (max < a[i])
//             max = a[i];
//     }
//     return max;
// }

// int main()
// {
//     int a[maxn];
//     int num;
//     scanf("%d", &num);
//     for (int i = 0, len = 0; i < num; i++)
//     {
//         scanf("%d", &len);
//         for (int i = 0; i < len; i++)
//             scanf("%d", &a[i]);
//         int m = find(a, len);
//         bucket_sort(a, len, m + 1);

//         for (int j = 0; j < len; j++)
//         {
//             if (j == len / 2)
//                 printf("\n");
//             printf("%d ", a[j]);
//         }
//     }
    
//     return 0;
// }