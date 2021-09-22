#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;
vector<int> pre, in, post, value;

void postorder(int root, int start, int end)
{
    if (start > end)
        return;
    int i = start;
    while (i < end && in[i] != pre[root])
        i++;
    postorder(root + 1, start, i - 1);
    postorder(root + 1 + i - start, i + 1, end);
    post.push_back(pre[root]);
}

int main()
{
    int num;
    scanf("%d", &num);
    char str[5];
    stack<int> s;
    int key = 0;
    while (~scanf("%s", str))
    {
        if (strlen(str) == 4)
        {
            int temp;
            scanf("%d", &temp);
            value.push_back(temp);
            pre.push_back(key);
            s.push(key++);
        }
        else
        {
            in.push_back(s.top());
            s.pop();
        }
    }

    postorder(0, 0, num - 1);
    printf("%d", value[post[0]]);

    for (int i = 1; i < num; i++)
        printf(" %d", value[post[i]]);

    return 0;
}