#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> temp;
    int M, N;
    cin >> M >> N;
    int num;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> num;
            temp[num]++;
            if (temp[num] > (M * N) / 2)
            {
                cout << num;
                return 0;
            }
        }
    }
}