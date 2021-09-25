#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct NODE
{
    int id, weight;
    vector<int> child;
} a[101];

bool cmp(int n, int m)
{
    return a[n].weight > a[m].weight;
}

vector<int> path;
void DFS(int node, int sum, int S)
{
    sum += a[node].weight;
    path.push_back(a[node].weight);

    if (sum > S)
    {
        /* 退出最后一个结点 */
        path.pop_back();
        return;
    }
    else if (sum == S && a[node].child.empty())
    {
        /* 输出 */
        for (int i = 0; i < path.size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << path[i];
        }
        cout << endl;
    }

    for (int i = 0; i < a[node].child.size(); i++)
    {
        DFS(a[node].child[i], sum, S);
    }
    /* 退出最后一个结点 */
    path.pop_back();
}

int main()
{
    int N, M, S;

    cin >> N >> M >> S;
    for (int i = 0; i < N; i++)
        cin >> a[i].weight;

    for (int i = 0, id, cn; i < M; i++)
    {
        cin >> id >> cn;
        for (int i = 0, temp; i < cn; i++)
        {
            cin >> temp;
            a[id].child.push_back(temp);
        }
        sort(a[id].child.begin(), a[id].child.end(), cmp);
    }

    DFS(0, 0, S);

    return 0;
}