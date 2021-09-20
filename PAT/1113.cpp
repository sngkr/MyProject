#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
    int n, sum=0, hsum=0;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
    }

    sort(v.begin(),v.end());
    for(int i=0; i<n/2; i++)
        hsum += v[i];
    printf("%d %d", n%2, sum-2*hsum);
    return 0;
}