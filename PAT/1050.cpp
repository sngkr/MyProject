#include <iostream>
using namespace std;
bool strb[256] = {false};
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    for (int j = 0; j < str2.length(); j++)
    {
        strb[str2[j]] = true;
    }
    for (int i = 0; i < str1.length(); i++)
    {
        if (strb[str1[i]] == false)
        {
            cout << str1[i];
        }
    }

    return 0;
    // cout<<str1<<endl;
    // cout<<str2<<endl;
}