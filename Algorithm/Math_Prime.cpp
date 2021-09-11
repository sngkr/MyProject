#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if (n == 1)
    {
        return true;
    }
    // 判断一个数能否被小于sqrt(n)的数整除
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int m;
    while (1)
    {
        scanf("%d", &m);
        if (is_prime(m))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

// bool is_prime(int n)
// {
//     if (n <= 3)
//     {
//         return n > 1;
//     }
//     // 判断一个数能否被小于sqrt(n)的数整除
//     for (int i = 3; i * i <= n; i += 2)
//     {
//         if (n % 2 == 0 || n % i == 0)
//             return false;
//     }
//     if (n % 2 == 0)
//         return false;
//     return true;
// }