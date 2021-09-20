#include <iostream>
#include <vector>
using namespace std;
vector<int> sum, result;
int n, m;
void Func(int i, int &j, int &tempsum)
{
    int left = i, right = n;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (sum[mid] - sum[i - 1] >= m)
            right = mid;
        else
            left = mid + 1;
    }
    j = right;
    tempsum = sum[j] - sum[i - 1];
}
int main()
{
    cin >> n >> m;
    sum.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    int min = sum[n];

    for (int i = 1; i <= n; i++)
    {
        int j, tempsum;
        Func(i, j, tempsum);
        if (tempsum > min)
            continue;
        if (tempsum >= m)
        {
            if (tempsum < min)
            {
                result.clear();
                min = tempsum;
            }
            result.push_back(i);
            result.push_back(j);
        }
    }

    for (int i = 0; i < result.size(); i += 2)
        cout << result[i] << "-" << result[i + 1] << endl;

    return 0;
}