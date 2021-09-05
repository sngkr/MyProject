#include <iostream>
#include <set>
using namespace std;

set<int> data[51];
int main()
{
    int times;
    scanf("%d", &times);
    for (int i = 0, num, j; i < times; i++)
    {
        scanf("%d", &num);
        while (num--)
        {
            scanf("%d", &j);
            data[i].insert(j);
        }
    }

    scanf("%d", &times);
    while (times--)
    {
        int l, r;
        scanf("%d %d", &l, &r);

        int same_num = 0,total_num = data[r-1].size() + data[l-1].size();
        // for (int i = 0; i < data[l-1].size(); i++)
        // {
        //     for (int j=0; i<data[r-1].size(); j++)
        //     if(data[l-1][i] == data[r-1][j])

        // }
        for(auto a = data[r-1].cbegin(); a!= data[r-1].cend(); a++)
        {
            if(data[l-1].count(*a) == 1)
                same_num++;
            
        }
        printf("%.1f%%\n", (float)100*same_num/(total_num-same_num));
    }
}

//