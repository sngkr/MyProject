//第一种解法
//读取所有，取出目标字符串
// #include <iostream>
// using namespace std;

// int main()
// {
//     int total_number, skip, winner;

//     cin >> total_number >> skip >> winner;

//     string str[1000], mir[1000];

//     for (int i = 0; i < total_number; i++)
//         cin >> str[i];

//     if (total_number < winner)
//     {
//         cout << "Keep going...";
//     }
//     else
//     {
//         int j = 0;
//         mir[j++] = str[winner - 1];
//         for (int k = winner - 1 + skip; k < total_number; k += skip)
//         {
//             string temp = str[k];
//             int flag = 0;
//             for (int l = 0; l < j; l++)
//             {
//                 if (temp == mir[l])
//                 {
//                     k = k + 1 - skip;
//                     flag = 1;
//                     break;
//                 }
//             }
//             if (flag == 0)
//                 mir[j++] = temp;
//         }

//         for (int n = 0; n < j; n++)
//             cout << mir[n] << endl;
//     }

//     return 0;
// }

//第二种解法
//从一堆目标中获取合适的，那么只需要一个数组保存就好了
// #include <iostream>
// using namespace std;

// int panduan(string a[], string b, int c)
// {
//     for (int i = 0; i < c; i++)
//     {
//         if (a[i] == b)
//             return 1;
//     }
//     return 0;
// }
// int main()
// {
//     int total_number, skip, winner;
//     cin >> total_number >> skip >> winner;

//     if (total_number < winner)
//     {
//         cout << "Keep going...";
//         return 0;
//     }

//     int num = winner, size = 0;
//     string temp, str[1000];
//     for (int i = 1; i <= total_number; i++)
//     {
//         cin >> temp;
//         if (i == num)
//         {
//             if (panduan(str, temp, size) == 1)
//                 num++;
//             else
//             {
//                 str[size++] = temp;
//                 num += skip;
//             }
//         }
//     }

//     for (int n = 0; n < size; n++)
//         cout << str[n] << endl;

//     return 0;
// }
//第三种解法
//和第二种思想一样，只不过用了map

#include <iostream>
#include <map>
using namespace std;
int main()
{
    int total_number, skip, winner;
    cin >> total_number >> skip >> winner;
    if (total_number < winner)
    {
        cout << "Keep going...";
        return 0;
    }

    string name;
    map<string, bool> have;
    for (int i = 1; i <= total_number; ++i)
    {
        cin >> name;
        if (have[name])
            winner += 1;
        if (!have[name] &&  winner== i)
        {
            have[name] = true;
            cout << name << endl;
            winner += skip;
        }
    }
    return 0;
}