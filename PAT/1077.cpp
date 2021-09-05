// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     vector<string> data;
//     int times;
//     cin >> times;
//     getchar();
//     string temp;
//     while (times--)
//     {
//         getline(cin, temp);
//         data.push_back(temp);
//     }

//     char c;
//     string str;
//     int n = 1;
//     int data_size = data.size();
//     for (int i = data[0].length() - 1; i > 0; i--)
//     {
//         int flag = 0;
//         if (i == data[0].length() - 1 || str.length())
//         {
//             for (int j = 1; j < data_size; j++)
//             {
//                 int location = data[j].length() - n;
//                 if (data[0][i] == data[j][location])
//                     flag = 1;
//                 else
//                 {
//                     flag = 0;
//                     break;
//                 }
//             }
//             if (flag)
//             {
//                 str.push_back(data[0][i]);
//                 n++;
//             }
//         }
//     }
//     if (str.size())
//     {
//         for (int i = str.length() - 1; i >= 0; i--)
//             cout << str[i];
//     }
//     else
//         cout << "nai";

//     return 0;
// }
// //出现了部分错误

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string str[100];
    int times;
    cin >> times;

    getchar();
    for (int i = 0; i < times; i++)
    {
        getline(cin, str[i]);
        reverse(str[i].begin(), str[i].end());
    }
    string ans;
    ans = str[0];
    for (int i = 1; i < times; i++)
    {
        int len = str[i].length();
        for (int j = 0; j < len; j++)
            if (str[i][j] == ans[j])
                continue;
            else
                ans = ans.substr(0, j);
    }
    reverse(ans.begin(), ans.end());
    if (ans == "")
        cout << "nai";
    else
        cout << ans;
}