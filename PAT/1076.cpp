#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int id, layer;
};

vector<vector<int>> v;

int bfs(node inode)
{
    bool inq[1010] = {false};
    queue<node> q;
    q.push(inode);
    inq[inode.id] = true;
    int cnt = 0;
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        int topid = top.id;

        for (int i = 0; i < v[topid].size(); i++)
        {
            int nextid = v[topid][i];
            if (inq[nextid] == false && top.layer < 1)
            {
                node next = {nextid, top.layer + 1};
                q.push(next);
                inq[next.id] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    int num, l;
    scanf("%d %d", &num, &l);

    v.resize(num + 1);

    int m, temp;
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &temp);
            v[temp].push_back(i);
        }
    }
    int k, tid;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &tid);
        node inode = {tid, 0};
        printf("%d\n", bfs(inode));
    }
    return 0;
}