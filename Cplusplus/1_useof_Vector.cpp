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

    cout << "\n\n vector.resize()!! \n\n";
    std::vector<int> myvector;

    // set some initial content:
    for (int i = 1; i < 10; i++)
        myvector.push_back(i);

    myvector.resize(5);
    myvector.resize(8, 100);
    myvector.resize(12);

    std::cout << "myvector contains:";
    for (int i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    return 0;
}
