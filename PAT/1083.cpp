#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct NODE
{
    string name, ID;
    int grade;
};

bool cmp(NODE a, NODE b)
{
    return a.grade > b.grade;
}
int main()
{
    int num;
    cin >> num;
    vector<NODE> temp(num);
    for (int i = 0; i < num; i++)
        cin >> temp[i].name >> temp[i].ID >> temp[i].grade;

    int L, H;
    cin >> L >> H;
    vector<NODE> data;
    for (int i = 0; i < num; i++)
    {
        if (temp[i].grade >= L && temp[i].grade <= H)
            data.push_back(temp[i]);
    }

    sort(data.begin(), data.end(), cmp);

    if (data.size())
    {
        for (int i = 0; i < data.size(); i++)
            cout << data[i].name << " " << data[i].ID << endl;
    }
    else
        cout << "NONE";

    return 0;
}