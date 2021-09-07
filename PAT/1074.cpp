#include <iostream>
using namespace std;
// 可能会输入无效结点

int main()

{
    int first, num, size;
    int list[100005], data[100005], next[100005];
    cin >> first >> num >> size;
    for (int i = 0, temp; i < num; i++)
    {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }

    int sum = 0;
    
    //不一定所有的结点都是有用的！！！！！！！！！！！
    while (first != -1)
//     for (int i = 0; i < num; i++)
    {
        list[sum++] = first;
        first = next[first];
    }

    //最重要的部分
    int result[100005];
    for (int i = 0; i < sum; i++)
        result[i] = list[i];
    for (int i = 0; i < (sum - sum % size); i++)
        result[i] = list[i / size * size + size - 1 - i % size];

    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);

    printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);

    return 0;
}