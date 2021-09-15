#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<int, vector<int>> data;
    int n, k;
    cin >> n >> k;

    for (int i = 0, t1, t2; i < n; i++)
    {
        cin >> t1 >> t2;
        data[t1].push_back(t2);
        data[t2].push_back(t1);
    }

    for (int i = 0; i < k; i++)
    {
        int flag = 0, a[100000] = {0};
        int cnt;
        cin >> cnt;
        vector<int> v(cnt);
        for (int j = 0; j < cnt; j++)
        {
            cin >> v[j];
            a[v[j]] = 1;
        }
        for (int j = 0; j < v.size(); j++)
        {
            for (int k = 0; k < data[v[j]].size(); k++)
                if (a[data[v[j]][k]] == 1)
                    flag = 1;
        }

        printf("%s\n", flag ? "No" : "Yes");
    }
    return 0;
}