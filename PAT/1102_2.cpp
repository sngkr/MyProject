#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct NODE
{
    int id, r, l;
    int index = 0, level = 0;
} a[100];

vector<NODE> v1;
void creatTree(int root, int index, int level)
{
    if (a[root].r != -1)
        creatTree(a[root].r, index * 2 + 1, level + 1);

    /* 在建树的过程中将，中序序列记录下来 */
    v1.push_back({root, 0, 0, index, level});

    if (a[root].l != -1)
        creatTree(a[root].l, index * 2 + 2, level + 1);
}

bool cmp1(NODE a, NODE b)
{
    if (a.level == b.level)
        return a.index < b.index;
    else
        return a.level < b.level;
}
int main()
{
    int num;
    cin >> num;
    string l, r;
    int have[100] = {0};
    for (int i = 0; i < num; i++)
    {
        a[i].id = i;
        cin >> l >> r;

        if (l != "-")
        {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        }
        else
        {
            a[i].l = -1;
        }

        if (r != "-")
        {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        }
        else
        {
            a[i].r = -1;
        }
    }

    int root = 0;
    while (have[root] != 0) /* 需要找到根的位置 */
        root++;

    creatTree(root, 0, 0);

    vector<NODE> v2(v1);
    sort(v2.begin(), v2.end(), cmp1);

    for (int i = 0; i < v2.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << v2[i].id;
    }
    cout << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << v1[i].id;
    }

    return 0;
}