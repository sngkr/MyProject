#include <iostream>
using namespace std;
int main()
{
    int a1, b1, c1, a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    int c = c1 + c2;
    int b = b1 + b2 + c / 29;
    c = c % 29;
    int a = a1 + a2 + b / 17;
    b = b % 17;
    printf("%d.%d.%d", a, b, c);
    return 0;
}