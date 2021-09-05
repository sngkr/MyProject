
// 1
// #include <iostream>
// #include <map>
// #include <set>
// using namespace std;

// bool find_N(int i, int N, string a)
// {
//     // if (i + N > a.length())
//     //     return false;

//     // int flag = 0;
//     // for (int j = i; j < i + N; j++)
//     // {
//     //     if (a[i] == a[j])
//     //         flag = 1;
//     //     else
//     //     {
//     //         flag = 0;
//     //         break;
//     //     }
//     // }
//     // if (flag)
//     //     return true;
//     // else
//     //     return false;
//     // if (a.find(b) == string::npos)
//     //     return false;
//     // else
//     //     return true;
//     string b;
//     while (N--)
//         b += a[i];
//     if(a.find(b) == i)
//         return true ;
//     else
//         return false;
// }

// int main()
// {
//     map<char, bool> Well;
//     set<char> Bad;
//     string data;

//     int N;
//     cin >> N;
//     cin >> data;
//     for (int i = 0; i < data.length(); i++)
//     {
//         if (find_N(i, N, data) && Bad.find(data[i]) == Bad.end())
//             Well[data[i]] = true;
//         else
//             Bad.insert(data[i]);
//     }

//     // for(int i=0; i<Well.size(); i++)
//     //     cout<<Well[i];
//     for (auto iter = Well.rbegin(); iter != Well.rend(); iter++)
//     {
//         cout << iter->first;
//     }

//     return 0;
// }

//2
// #include <iostream>
// #include <map>
// #include <set>
// using namespace std;
// //待改正：只有连续出现N的倍数的字符才可能是坏键，不是连续出现了N次就算是坏键
// bool find_N(int i, int N, const string a)
// {
//     string same;
//     while (N--)
//         same += a[i];
//     if (a.find(same) == i)
//         return true;
//     else
//         return false;
// }
// int main()
// {
//     map<char, bool> Well;
//     set<char> Bad;
//     string data;
//     int N;
//     cin >> N >> data;
//     for (int i = 0; i < data.length(); i++)
//     {
//         if (find_N(i, N, data) && Bad.find(data[i]) == Bad.end())
//             Well[data[i]] = true;
//         // Well.insert({data[i], true});
//         // else if (Well[data[i]] == true && !find_N(i, N, data))
//         //     Well[data[i]] = false;
//         else if(!find_N(i, N, data) && Bad.find(data[i]) == Bad.end())
//             Well[data[i]] = false;
//         else
//             Bad.insert(data[i]);
//     }
//     //还需要再次确认不会出现 3 s = aaabbbcccaabb 存在坏键
//     for (auto iter = Well.cbegin(); iter != Well.cend(); iter++)
//     {
//         // if (Bad.find(iter->first) != Bad.end())
//         //     Well[iter->first] = false;
//         if (Well[iter->first])
//             cout << iter->first;
//     }
//     cout << endl;
//     // for (auto temp = Bad.cbegin(); temp != Bad.cend(); temp++)
//     // {
//     //     cout << *temp;
//     // }
//     // cout << endl;
//     for (int i = 0; i < data.length(); i++)
//     {
//         cout << data[i];
//         if (Well[data[i]])
//             i += N - 1;
//     }
//     return 0;
// }

// 3

#include <iostream>
#include <map>
using namespace std;
//：只有连续出现N的倍数的字符才可能是坏键，不是连续出现了N次就算是坏键
//!!!!!!!!!!!找好键就ok
int main()
{
    map<char, bool> Well;
    map<char, bool> Appear;
    string data;
    int N;
    cin >> N >> data;
    for (int i = 0, j; i < data.length();)
    {
        j = i + 1;
        while (j < data.length() && data[j] == data[j - 1])
            j++;

        if ((j - i) % N != 0) //找出不是坏键 --- 更好找，好操作、、不是坏键的情况多，复杂容易出错
            Well[data[i]] = true;

        i = j;
    }

    string result;
    for (int i = 0; i < data.length();)
    {
        result += data[i];
        if (Well[data[i]])//好键
        {
            i++;
        }
        else//坏键
        {
            if (!Appear[data[i]])//打印出坏键，不重复出现
            {
                cout<<data[i];
                Appear[data[i]] = true;
            }
            i += N;
        }
    }
    cout << endl;
    cout << result;
    return 0;
}
