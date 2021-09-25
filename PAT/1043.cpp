#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail)
{
    if (root > tail)
        return;
    int i = root + 1, j = tail;
    if (!isMirror)
    {
        while (i <= tail && pre[root] > pre[i])
            i++;
        while (j > root && pre[root] <= pre[j])
            j--;
    }
    else
    {
        while (i <= tail && pre[root] <= pre[i])
            i++;
        while (j > root && pre[root] > pre[j])
            j--;
    }
    if (i - j != 1)
        return;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main()
{
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if (post.size() != n)
    {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if (post.size() == n)
    {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++)
            printf(" %d", post[i]);
    }
    else
    {
        printf("NO");
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 1001;

struct Node
{
    int data;
    Node *left, *right;
};

void Insert(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (data < root->data)
        Insert(root->left, data);
    else
        Insert(root->right, data);
}

void preOrder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    v.push_back(root->data);
    preOrder(root->left, v);
    preOrder(root->right, v);
}

void preOrderMirror(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    v.push_back(root->data);
    preOrderMirror(root->right, v);
    preOrderMirror(root->left, v);
}

void postOrder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    postOrder(root->left, v);
    postOrder(root->right, v);
    v.push_back(root->data);
}

void postOrderMirror(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    postOrderMirror(root->right, v);
    postOrderMirror(root->left, v);
    v.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;

int main()
{
#if ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int N, data;
    scanf("%d", &N);
    Node *root = NULL;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        Insert(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if (origin == pre)
    {
        printf("YES\n");
        for (int i = 0; i < post.size(); i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", post[i]);
        }
    }
    else if (origin == preM)
    {
        printf("YES\n");
        for (int i = 0; i < postM.size(); i++)
        {
            if (i != 0)
                printf(" ");
            printf("%d", postM[i]);
        }
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}