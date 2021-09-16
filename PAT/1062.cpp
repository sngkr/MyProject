#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct NODE
{
    string ID;
    int virtue, talent;
};
bool cmp(NODE a, NODE b)
{
    if ((a.virtue + a.talent) != (b.virtue + b.talent))
        return (a.virtue + a.talent) > (b.virtue + b.talent);
    else if (a.virtue != b.virtue)
        return a.virtue > b.virtue;
    else
        return a.ID < b.ID;
}
int main()
{
    int num, L, H;
    cin >> num >> L >> H;
    vector<NODE> temp(num);
    vector<NODE> data[4];
    for (int i = 0; i < num; i++)
    {
        cin >> temp[i].ID >> temp[i].virtue >> temp[i].talent;
        if (temp[i].virtue < L || temp[i].talent < L) //这里以及所有元素判定输入都很容易出错
            continue;
        else if (temp[i].virtue >= H && temp[i].talent >= H)
            data[0].push_back(temp[i]);
        else if (temp[i].virtue >= H && temp[i].talent < H)
            data[1].push_back(temp[i]);
        else if (temp[i].virtue < H && temp[i].talent < H && temp[i].virtue >= temp[i].talent)
            data[2].push_back(temp[i]);
        else
            data[3].push_back(temp[i]);
    }

    cout << data[0].size() + data[1].size() + data[2].size() + data[3].size() << endl;

    for (int i = 0; i < 4; i++)
    {
        sort(data[i].begin(), data[i].end(), cmp);
        for (int j = 0; j < data[i].size(); j++)
            cout << data[i][j].ID << " " << data[i][j].virtue << " " << data[i][j].talent << endl;
    }
    return 0;
}
