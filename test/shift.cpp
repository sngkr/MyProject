#include <iostream>

using namespace std;
#define PGSHIFT 12
#define PXMASK 0x1FF // 9 bits
#define PXSHIFT(level) (PGSHIFT + (9 * (level)))
#define PX(level, va) ((((uint64_t)(va)) >> PXSHIFT(level)) & PXMASK)
#define hh (1 << 2)

int main()
{
    uint32_t a = 0x0fff0fff;
    char b[100];
    cout << a << endl;
    itoa(a, b, 2);
    cout << b << endl;
    itoa((a >> PGSHIFT), b, 2);

    cout << "a>>PGSHIFT:" << b << endl;

    itoa(PXMASK, b, 2);

    cout << b << endl;

    itoa(((a >> 10) << 12), b, 2);

    cout << b << endl;
    PX(2, a);
    cout << a << endl;
    return 0;
}
