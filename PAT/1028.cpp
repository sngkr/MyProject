#include <iostream>
#include <algorithm>
using namespace std;

struct NODE
{
    int num;
    string name;
    int score;
} node[100001];

int column;
bool cmp(NODE a, NODE b)
{
    if (column == 1)
    {
        return a.num < b.num;
    }
    else if (column == 2)
    {
        if (a.name == b.name)
            return a.num < b.num;
        else
            return a.name < b.name;
    }
    else
    {
        if (a.score == b.score)
            return a.num < b.num;
        else
            return a.score <= b.score;
    }
}

int main()
{
    int num;
    cin >> num >> column;

    for (int i = 0; i < num; i++)
        cin >> node[i].num >> node[i].name >> node[i].score;

    sort(node, node + num, cmp);

    for (int i = 0; i < num; i++)
    {
        printf("%06d %s %d\n", node[i].num, node[i].name.c_str(), node[i].score);
    }
    return 0;
}