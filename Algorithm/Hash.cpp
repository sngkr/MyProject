#include <iostream>
using namespace std;
int hashtable[100] = {0};
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
    cin>>size>>amount;
        for (int i = 0, key; i < amount; i++)
    {
        cin >> key;
        if (i)
            cout << " ";

        insert(key, size);
    }
}