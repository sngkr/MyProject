#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int stu_num, cor_num;
    scanf("%d %d", &stu_num, &cor_num);

    map<string, vector<int>> data;
    string name;
    for (int i = 0, j, k; i < cor_num; i++)
    {
        scanf("%d %d", &j, &k);
        for (int l = 0; l < k; l++)
        {
            cin >> name;
            data[name].push_back(j);
        }
    }

    for (int i = 0; i < stu_num; i++)
    {
        cin >> name;
        sort(data[name].begin(), data[name].end());

        cout << name << " " << data[name].size();
        // printf("%s %lu", name.c_str(), data[name].size());
        // for (auto temp = data[name].cbegin(); temp != data[name].cend(); temp++)
        // {
        //     printf(" %d", *temp);
        // }
        for (int j = 0; j < data[name].size(); j++)
            // printf(" %d", data[name][j]);
            cout << " " << data[name][j];
        printf("\n");
    }
    return 0;
}
