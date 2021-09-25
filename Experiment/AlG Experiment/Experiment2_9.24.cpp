#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> Gray(int n)
{

    if (n == 0)
        return vector<string>{"0"};
    else if (n == 1)
        return vector<string>{"0", "1"};

    vector<string> temp = Gray(n - 1);
    vector<string> result;
    for (auto iter = temp.cbegin(); iter != temp.cend(); iter++)/* "0" 加上 Gray(n-1) 的正序 */
        result.push_back("0" + *iter);

    for (auto iter = temp.crbegin(); iter != temp.crend(); iter++)/* "1" 加上 Gray(n-1) 的逆序 */
        result.push_back("1" + *iter);

    return result;
}

int main()
{
    int num;
    cin >> num;

    vector<string> result = Gray(num);

    for (auto it = result.cbegin(); it != result.cend(); it++)
        cout << *it << endl;
    return 0;
}