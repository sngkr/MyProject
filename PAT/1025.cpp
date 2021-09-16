#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct NODE
{
    string ID;
    int score, final, location, local;
};

bool cmp(NODE a, NODE b)
{
    return (a.score == b.score) ? a.ID < b.ID : a.score > b.score;
}
int main()
{
    int num;
    cin >> num;
    int start = 0;
    vector<NODE> result;
    for (int i = 0, temp; i < num; i++)
    {
        cin >> temp;
        vector<NODE> data(temp);
        for (int j = 0; j < temp; j++)
        {
            cin >> data[j].ID >> data[j].score;
            data[j].location = i + 1;
        }

        sort(data.begin(), data.end(), cmp);
        data[0].local = 1;
        result.push_back(data[0]);
        for (int j = 1; j < data.size(); j++)
        {
            data[j].local = (data[j - 1].score == data[j].score) ? data[j - 1].local : j + 1;
            result.push_back(data[j]);
        }
    }

    sort(result.begin(), result.end(), cmp);
    result[0].final = 1;

    for (int i = 1; i < result.size(); i++)
    {
        result[i].final = (result[i].score == result[i - 1].score) ? result[i - 1].final : i + 1;
    }

    cout << result.size() << endl;

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].ID << " " << result[i].final << " " << result[i].location << " " << result[i].local << endl;
    }

    return 0;
}