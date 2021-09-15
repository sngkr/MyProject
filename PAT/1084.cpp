#include <iostream>
using namespace std;

int main()
{
    string a, b, result;
    cin >> a >> b;
    for(int i=0; i<a.length(); i++)
    {
        if(b.find(a[i]) == string::npos && result.find(toupper(a[i])) == string::npos)
            result += toupper(a[i]);
    }
    cout << result ;
    return 0;
}