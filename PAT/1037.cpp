#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1;
    vector<int> data1(n1);
    for (int i = 0; i < n1; i++)
        cin >> data1[i];
    cin >> n2;
    vector<int> data2(n2);
    for (int i = 0; i < n2; i++)
        cin >> data2[i];
    sort(data1.begin(), data1.end());

    sort(data2.begin(), data2.end());

    int result = 0;
    /* 两者不一定等长 */
    // for (int i = 0, j = 0; i < n1 && j < n2; i++, j++)
    // {
    //     if (data1[i] * data2[j] >= 0)
    //         result += data1[i] * data2[j];
    // }
    for (int i = 0, j = 0; i < n1 && j < n2; i++, j++)
    {
        if (data1[i] < 0 && data2[j] < 0)
            result += data1[i] * data2[j];
    }

    for (int i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (data1[i] > 0 && data2[j] > 0)
            result += data1[i] * data2[j];
    }
    cout << result;
    return 0;
}