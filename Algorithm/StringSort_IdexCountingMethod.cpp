#include <iostream>
using namespace std;

int main()
{
    int key[] = {4, 5, 6, 6, 1, 1, 3, 3};
    int Count[10] = {0};
    int temp[10];
    //1、频率统计：记录每个关键字的出现次数
    for (int i = 0; i < 8; i++)
    {
        Count[key[i] + 1]++;//为了方便转化为索引，小tips
    }
    //2、将频率转化为索引：计算每一个键在排序结果的起始位置
    for (int i = 0; i < 8; i++)
    {
        Count[i + 1] += Count[i];
    }
    //3、数据分类：根据索引得到排序结果
    for (int i = 0; i < 8; i++)
    {
        temp[Count[key[i]]++] = key[i];
    }
    //4、回写（或者直接输出）
    for (int i = 0; i < 8; i++)
        cout << temp[i];
    return 0;
}

// //
// int N = a.length;

// int[] count = new int[R + 1];
// String[] aux = new String[N];

// //统计频率：
// for (int i = 0; i < N; i++)
// {
//     count[a[i].key() + 1]++;
// }
// //计算起始索引:
// for (int r = 0; r < R; r++)
// {
//     count[r + 1] += count[r];
// }
// //数据分类：
// for (int i = 0; i < N; i++)
// {
//     aux[count[a[i].key()]++] = a[i];
// }
// //回写：
// for (int i = 0; i < N; i++)
// {
//     a[i] = aux[i];
// }