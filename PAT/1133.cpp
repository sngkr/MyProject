#include <iostream>
#include <vector>
using namespace std;
struct NODE
{
    int first;
    int data;
    int next;
} node[100000];
// int data[100000], nex[100000]; //存储next、data
vector<NODE> v[3];
// vector<int> v[3];
int main()
{
    int first, num, N;
    cin >> first >> num >> N;

    for (int i = 0, addr = 0, temp = 0, next = 0; i < num; i++)
    {
        scanf("%d", &addr);
        scanf("%d %d", &node[addr].data, &node[addr].next);
        node[addr].first = addr;
    }

    for (int i = first; i != -1; i = node[i].next)
    {
        if (node[i].data < 0)
            v[0].push_back(node[i]);
        else if (node[i].data > N)
            v[2].push_back(node[i]);
        else
            v[1].push_back(node[i]);
    }

    int flag = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (flag == 0)
            {
                printf("%05d %d ", v[i][j].first, v[i][j].data);
                flag = 1;
            }
            else
                printf("%05d\n%05d %d ", v[i][j].first, v[i][j].first, v[i][j].data);
        }
    }
    printf("-1");
    return 0;
}