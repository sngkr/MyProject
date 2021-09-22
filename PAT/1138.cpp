#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre;
bool flag = false;
void postorder(int preroot, int inl, int inr)
{
    if (inl > inr || flag == true)
        return;
    int i = inl;
    while (in[i] != pre[preroot])
        i++;
    postorder(preroot + 1, inl, i - 1);
    postorder(preroot + 1 + i - inl, i + 1, inr);
    if (flag == false)
    {
        cout << in[i];
        flag = true;
    }
}

int main()
{
    int num;
    cin >> num;
    pre.resize(num);
    in.resize(num);
    for (int i = 0; i < num; i++)
        cin >> pre[i];
    for (int i = 0; i < num; i++)
        cin >> in[i];

    postorder(0, 0, num - 1);

    return 0;
}