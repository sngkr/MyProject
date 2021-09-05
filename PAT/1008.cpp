
#include <iostream>
using namespace std;
int main()
{
    int n;
    int now = 0, next;
    int time = 0;
    cin >> n;
    while (n--)
    {
        cin >> next;
        if (next > now)
            time += 6 * (next - now) + 5;
        else
            time += 4 * (now - next) + 5;

        now = next;
    }
    cout << time;
    return 0;
}