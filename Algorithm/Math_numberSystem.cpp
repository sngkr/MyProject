#include <iostream>
using namespace std;

long long convert(string a, long long radix)
{
    long long base = 1, num = 0;
    for (auto p = a.cbegin(); p != a.cend(); p++)
    {
        int temp = isdigit(*p) ? *p - '0' : *p - 'a' + 10;
        num += temp * base;
        base *= radix;
    }
    return num;
}
int main()
{
    string a="b";
    long long p = 10;

    cout<<convert(a, 10);
    return 0;
}