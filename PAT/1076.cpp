#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int id, layer;
};
int deep;
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
        // printf("\n");
        node top = q.front();
        q.pop();
        int topid = top.id;
        // printf("topid: %d\n", topid);
        for (int i = 0; i < v[topid].size(); i++)
        {
            int nextid = v[topid][i];
            // printf(" %d ", nextid);
            if (inq[nextid] == false && top.layer < deep)
            {
                node next = {nextid, top.layer + 1};
                q.push(next);
                inq[next.id] = true;
                cnt++;
                // printf("cnt: %d \n", cnt);
            }
        }
        // printf("\n");
    }

    return cnt;
}

int main()
{
    int num;
    scanf("%d %d", &num, &deep);

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

    // for (int i = 1; i < 8; i++)
    // {
    //     printf("%d :", i);
    //     for (int j = 0; j < v[i].size(); j++)
    //         printf("%d ", v[i][j]);

    //     printf("\n");
    // }
    return 0;
}