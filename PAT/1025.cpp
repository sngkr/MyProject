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
    return (a.score == b.score) ? a.ID < b.ID : a.score < b.score;
}
int main()
{
    int num;
    cin >> num;
    int start = 0;
    for (int i = 0, temp; i < num; i++)
    {
        cin >> temp;
        vector<NODE> data(temp);
        for (int j = 0; j < temp; j++)
        {
            cin >> data[i].ID >> data[i].score;
            data[i].location = i + 1;
        }

        sort(data.begin(), data.end(), cmp);
    }
}