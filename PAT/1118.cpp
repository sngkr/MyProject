#include <iostream>
#include <vector>
using namespace std;

vector<int> cluster;
int father[10001];
int find_father(int n)
{
    if (father[n] == n)
        return n;
    else
        return (father[n] = find_father(father[n]));
}

void merge(int a, int b)
{
    father[find_father(a)] = find_father(b);
}
void init()
{
    for (int i = 0; i < 10005; i++)
        father[i] = i;
}



// vector<int> father;
// int main()
// {
//     int npic;
//     scanf("%d", &npic);
//     cluster.resize(npic);
//     /* 把族群当做并查集元素还是小鸟，答案是族群 */
//     for (int i = 1; i <= npic; i++)
//         cluster[i] = i;

//     for (int i = 1; i <= npic; i++)
//     {
//         int temp;
//         scanf("%d", &temp);
//         for (int j = 0; j < temp; j++)
//         {
//             int b;
//             scanf("%d", &b);
//             if (father[b] == 0)
//             {
//                 father[b] = i;
//                 //cluster[i]++;
//             }

//             merge(i, find_father(father[b]));
//         }
//     }

//     for (int i = 1; i <= npic; i++)
//     {
//         cout << cluster[i] << " " << i << endl;
//     }
//     return 0;
// }