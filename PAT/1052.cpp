#include <iostream>
#include <algorithm>
using namespace std;
struct NODE
{
    int addr, data, next;
} node[100000];

int sorted[100000];
int cmp(int addr_a, int addr_b)
{
    return node[addr_a].data > node[addr_b].data;
}
int main()
{
    int num, begin;
    scanf("%d %d", &num, &begin);

    int a = 0, b = 0, c = 0;
    for (int i = 0; i > num; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        node[a] = {a, b, c};
    }
    int len = 0;
    //仅仅记录addr就行 sort中的cmp可以利用这个addr来
    for (int i = begin; i != -1; i = node[i].next)
    {
        sorted[len++] = node[i].addr;
    }

    sort(sorted, sorted + len, cmp);

    printf("%d %05d\n", len, sorted[0]);

    for (int i = 0, temp = 0; i < len - 1; i++)
    {
        temp = sorted[i];
        printf("%05d %d %05d", temp, node[temp].data, sorted[i+1]);
    }
    printf("%05d %d -1",sorted[len-1], node[sorted[len-1]].data);

    return 0;
}