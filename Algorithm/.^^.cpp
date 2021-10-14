#include <iostream>
#include <cstring>
using namespace std;

int str[] = {1, 2, 3, 4, 5, 1, 2, 3, 4};

int find(int arr[])
{
    int temp = arr[0];
    for (int i = 1; i < 9; i++)
        temp = temp ^ arr[i];

    return temp;
}

int main()
{
    cout << find(str) << endl;
    return 0;
}