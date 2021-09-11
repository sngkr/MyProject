#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(char a, char b){return a>b;}
int main()
{
    string a;
    cin>>a;
    a.insert(0, 4-a.length(), '0');//不是四位数的用0补齐
    do
    {
        /* code */
        string b=a, c=a;

        sort(b.begin(), b.end(), cmp);
        sort(c.begin(), c.end());
        int res = stoi(b) - stoi(c);

        a = to_string(res);
         a.insert(0, 4-a.length(), '0');//不是四位数的用0补齐
         cout<< b << " - " << c << " = " <<a <<endl;

    } while (a != "6174" && a!= "0000");
    return 0;
}