#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

struct NODE
{
    string id;
    int value;
} a[10001];

bool cmp(const NODE &a, const NODE &b)
{
    return a.value != b.value ? a.value > b.value : a.id < b.id;
}
int main()
{
    int num, ask;

    scanf("%d %d", &num, &ask);

    for (int i = 0; i < num; i++)
        cin >> a[i].id >> a[i].value;

    for (int i = 1, temp; i <= ask; i++)
    {
        int case2 = 0, case2_sum = 0;
        vector<NODE> kl;
        string s;
        cin >> temp >> s;
        printf("Case %d: %d %s\n", i, temp, s.c_str());
        if (temp == 1)
        {
            for (int u = 0; u < num; u++)
                if (a[u].id[0] == s[0])
                    kl.push_back(a[u]);
        }
        else if (temp == 2)
        {
            for (int u = 0; u < num; u++)
                if (a[u].id.substr(1, 3) == s)
                {
                    case2++;
                    case2_sum += a[u].value;
                }
            if (case2)
                printf("%d %d\n", case2, case2_sum);
        }
        else if (temp == 3)
        {
            unordered_map<string, int> op;
            for (int u = 0; u < num; u++)
            {
                if (a[u].id.substr(4, 6) == s)
                    op[a[u].id.substr(1, 3)]++;
            }
            for (auto it : op)
                kl.push_back({it.first, it.second});
        }
        sort(kl.begin(), kl.end(), cmp);

        for (int u = 0; u < kl.size(); u++)
            printf("%s %d\n", kl[u].id.c_str(), kl[u].value);

        if (((temp == 1 || temp == 3) && kl.size() == 0) || (temp == 2 && case2 == 0))
            printf("NA\n");
    }
    return 0;
}