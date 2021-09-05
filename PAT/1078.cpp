#include <iostream>

using namespace std;
int hashtable[10000] = {0};

bool isprime(int n)
{
    if (n <= 3)
    {
        return n > 1;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void insert(int key, int len)
{
    int idex;
    for (int i = 0; i < len; i++)
    {
        idex = (key + i * i) % len;
        if (!hashtable[idex])
        {
            hashtable[idex] = 1;
            cout << idex %len ;
            return;
        }
    }
    cout << "-";
}

int main()
{
    int size, amount;
    cin >> size >> amount;
    while (!isprime(size))
        size++;

    for (int i = 0, key; i < amount; i++)
    {
        cin >> key;
        if (i)
            cout << " ";

        insert(key, size);
    }

    return 0;
}