#include <iostream>
using namespace std;
int main()
{
    int n, t, cnt = 0, a[100010];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[t] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            swap(a[0], a[a[0]]);
            cnt++;
        }
        if(i != a[i])
        {
            swap(a[0], a[i]);
            cnt ++;
        }
    }
    cout << cnt;
}