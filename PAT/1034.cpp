// #include <iostream>
// #include <algorithm>
// #include <string>
// #define MAXN 1005

// using namespace std;
// int father[MAXN], cluster[MAXN], Num[MAXN], Result[MAXN];
// int Root[MAXN];
// // bool cmp(int a, int b)
// // {
// //     return a < b;
// // }
// void init()
// {
//     for (int i = 0; i < MAXN; i++) 
//         father[i] = i;
// }
// int find(int x)
// {
//     return (father[x] == x) ? x : (father[x] = find(father[x]));
// }

// void merge(int x, int y)
// {
//     int temp = find(y);
//     father[find(x)] = temp;
//     Root[temp] = 1;
// }

// int main()
// {
//     int N, K;
//     scanf("%d %d", &N, &K);
//     init();
//     for (int i = 0, m1, m2, w, temp; i < N; i++)
//     {
//         scanf("%d %d %d", &m1, &m2, &w);
//         if(find(m1) == m1)
//             merge(m2,m1);
//         else if(find(m2) == m2)
//         merge(m1, m2);
//         temp = find(m2);
//         cluster[temp] += w;
//         Num[temp]++;
//     }
//     int cnt = 0;
//     for (int i = 0; i < MAXN; i++)
//     {
//         if (cluster[i] > K)
//         {
//             Result[cnt++] = i;
//         }
//     }
//     sort(Result, Result+cnt);
//     // for(int i=0; i<cnt; i++)
//     // {
//     //     string a = to_string(Result[i]);
//     //     printf("%s %d\n",a.c_str(), Num[Result[i]]);
//     // }

//     for(int i=0; i<cnt; i++)
//     {
//         printf("%d %d\n", Result[i], Num[Result[i]]);
//     }
//     return 0;
// }

#include <iostream>
#include <map>

using namespace std;

map<int, string> inToString;
map<string, int> stringToInt;
map<string, int> ans;

int G[2010][2010], weight[2010];
bool vis[2010];

int idNumber = 1;
int N, K;
int conversion(string s)
{
    if (stringToInt[s] == 0)
    {
        stringToInt[s] = idNumber;
        inToString[idNumber] = s;
        return idNumber++;
    }
    else
    {
        return stringToInt[s];
    }
}

void dfs(int id, int &head, int &total_weight, int &numMember)
{
    vis[id] = true;
    numMember++;
    if (weight[id] > weight[head])
        head = id;
    for (int i = 1; i < idNumber; i++)
    {
        if (G[id][i] > 0)
        {
            total_weight += G[id][i];
            G[id][i] = G[i][id] = 0;
            if (vis[i] == false)
                dfs(i, head, total_weight, numMember);
        }
    }
}

void dfsTravel()
{
    for (int i = 1; i < idNumber; i++)
    {
        if (vis[i] == false)
        {
            int head = i, numMember = 0, total_weight = 0;
            dfs(i, head, total_weight, numMember);

            if (numMember > 2 && total_weight > K)
                ans[inToString[head]] = numMember;
        }
    }
}
int main()
{
    scanf("%d %d", &N, &K);
    string Name1, Name2;
    int time;
    for (int i = 0; i < N; i++)
    {
        cin >> Name1 >> Name2 >> time;
        int n1 = conversion(Name1);
        int n2 = conversion(Name2);
        weight[n1] += time;
        weight[n2] += time;
        G[n1][n2] += time;
        G[n2][n1] += time;
    }
    dfsTravel();
    
    cout << ans.size() << endl;
    for(auto it = ans.begin() ; it!= ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
