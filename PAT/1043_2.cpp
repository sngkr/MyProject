#include <iostream>
#include <vector>
using namespace std;

vector<int> post, value, in;

void getpost(int root, int tail)
{
    if (root > tail) /* why？ ：常规操作，遍历完返回*/
        return;
    int i = root + 1, j = tail;
    while (i <= tail && value[root] > value[i]) //这个地方value[root] > value[i] 里面的'>' 是根据BST的性质来的
        i++;                                    //i的初始值不是0，那么可以肯定不是算数量，考虑后得知是找下标

    while (j > root && value[root] <= value[j]) //这个地方value[root] <= value[i] 里面的'<=' 是根据BST的性质来的
        j--;                                    /* j的初始值不是0，那么可以肯定不是算数量 */

    if (i - j != 1) /* why? :这个只有在所给序列不是BST的中序遍历时候会用到*/
        return;
    getpost(root + 1, j);
    in.push_back(value[root]);
    getpost(i, tail);
    post.push_back(value[root]);
}
int main()
{
    int num;
    cin >> num;
    for (int i = 0, temp; i < num; i++)
    {
        cin >> temp;
        value.push_back(temp);
    }

    getpost(0, num - 1);
    cout << "\npost" << endl;
    for (int i = 0; i < post.size(); i++)
        cout << post[i] << " ";

    cout << "\nin" << endl;
    for (int i = 0; i < in.size(); i++)
        cout << in[i] << " ";

    return 0;
}