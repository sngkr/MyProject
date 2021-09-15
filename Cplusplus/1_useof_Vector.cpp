#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> data{3, 5, 3, 8, 5, 6, 22, 4, 5, 6};

    cout << "\n /* 测试sort中指针是否可以加常数 */" << endl;
    sort(data.begin() + 6, data.end());
    for (auto i : data)
        cout << i << " ";

    sort(data.begin(), data.end());

    cout << "\n/* 测试得知sort默认升序排列 */" << endl;
    for (auto i : data)
        cout << i << " ";
    return 0;
}
