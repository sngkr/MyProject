#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    map<int, vector<string>> data;
    string name;

    int stu_num, cou_num;
    // cin >> stu_num >> cou_num;
    scanf("%d %d", &stu_num, &cou_num);
    for (int i = 0; i < stu_num; i++)
    {
        cin >> name;
        int times;
        // cin >> times;
        scanf("%d", &times);
        for (int j = 0; j < times; j++)
        {
            int temp;
            // cin >> temp;
            scanf("%d", &temp);
            data[temp].push_back(name);
        }
    }

    for (int i = 1; i <= cou_num; i++)
    {
        // cout << i << " " << data[i].size() << endl;
        printf("%d %lu\n", i, data[i].size());

        sort(data[i].begin(), data[i].end());
        for (int j = 0; j < data[i].size(); j++)
            // cout << data[i][j] << endl;
            printf("%s\n", data[i][j].c_str());
    }

    return 0;
}

//为什么cout会比printf慢
//cout还需要缓冲
//另一种方法是不用map， 利用课程序号的特点