#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> v(num + 1);

    for (int i = 1; i <= num; i++)
        cin >> v[i];

    for (int i = 1; i <= num; i++)
    {
        for (int j = i + 1; j <= num; j++)
        {
            vector<int> lie, a(num + 1, 1); //保存说谎者的序号以及狼和好人的辨别
            a[i] = a[j] = -1;               //假设这两个为狼

            for (int k = 1; k <= num; k++)
                if (v[k] * a[abs(v[k])] <0)
                    lie.push_back(k);
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0)
            {
                cout << i << " " << j;
                return 0;
            }
        }
    }

    cout << "No Solution";
    return 0;
}