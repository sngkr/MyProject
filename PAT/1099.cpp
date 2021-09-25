#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> keys;
int y = 0;
struct NODE
{
    int r, l,index, key;
} a[101];

bool cmp(NODE a, NODE b)
{
    if(a.index == b.index)
        return a.key < b.key;
    else
        return a.index < b.index;
}
void creatTree(int root, int level)
{
    if (root == -1)
        return;
    creatTree(a[root].l, level + 1);
    a[root] = {a[root].r, a[root].l,level,keys[y++]};
    creatTree(a[root].r, level + 1);
}

int main()
{
    int num;
    cin >> num;
    keys.resize(num);
    for (int i = 0, r, l; i < num; i++)
        cin >> a[i].l >> a[i].r;

    for (int i = 0; i < num; i++)
        cin >> keys[i];

    sort(keys.begin(), keys.end());
    creatTree(0,0);
    sort(a,a+num,cmp);

    for(int i=0; i<num; i++)
    {
        if(i != 0)
            cout << " ";
        cout << a[i].key;
    }
    return 0;
}