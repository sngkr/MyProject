#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct NODE
{
    string name;
    int age, Net_Worth;
};

bool cmp(NODE a, NODE b)
{
    if (a.Net_Worth != b.Net_Worth)
        return a.Net_Worth > b.Net_Worth;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return a.name < b.name;
}
int main()
{
    int num, times;
    cin >> num >> times;
    vector<NODE> data(num);
    for (int i = 0; i < num; i++)
        cin >> data[i].name >> data[i].age >> data[i].Net_Worth;

    for (int i = 0; i < times; i++)
    {
        vector<NODE> temp;
        int n, agel, ageh;
        cin >> n >> agel >> ageh;
        for (int j = 0; j < data.size(); j++)
        {
            if (data[j].age >= agel && data[j].age <= ageh)
                temp.push_back(data[j]);
        }

        sort(temp.begin(), temp.end(), cmp);

        cout << "Case #" << i + 1 << ":" << endl;
        int flag = 0;
        for (int j = 0; j < temp.size() && j < n; j++)
        {
            cout << temp[j].name << " " << temp[j].age << " " << temp[j].Net_Worth << endl;
            flag = 1;
        }
        if (!flag)
            cout << "None" << endl;
    }

    return 0;
}