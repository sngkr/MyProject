
// //substr
// #include<string>
// #include<iostream>
// using namespace std;
// int main()
// {

//     string str1("Heterological paradoxes are persistent.");
//     cout<<"The original string str1 is:"<<endl;
//     cout<<str1<<endl;
//     basic_string<char>str2=str1.substr(6,7);
//     cout<<"The substring str2 copied is:"<<str2<<endl;
//     basic_string<char>str3=str1.substr();
//     cout<<"The default substring str3 is:"<<endl;
//     cout<<str3<<endl;
//     cout<<"which is the entire original string."<<endl;
//     return 0;
// }
//find

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a = "abcdefghigklmn";
    string b = "def";
    string c = "123";
    string::size_type idx;

    idx = a.find(b);         //在a中查找b.
    if (idx == string::npos) //不存在。
        cout << "not found\n";
    else //存在。
        cout << "found\n";
    idx = a.find(c);         //在a中查找c。
    if (idx == string::npos) //不存在。
        cout << "not found\n";
    else //存在。
        cout << "found\n";
    return 0;
}
