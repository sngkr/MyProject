#include <iostream>
using namespace std;
long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    cout << gcd(10, 25) << endl;
    cout << gcd(12, 7) << endl;

    return 0;
}