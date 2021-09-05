#include <iostream>
// #include <string>
using namespace std;
int main()
{
    string str;
    int k, times;
    cin >> str >> times;

    for (int i = 1; i < times; i++)
    {
        string temp;
        for (int j = 0; j < str.length(); j = k)
        {
            for (k = j; (k < str.length() && str[k] == str[j]); k++);
                temp += str[j] + to_string(k - j);
        }
        str = temp;
    }
    cout << str;
    return 0;
}

// #include <iostream>
// using namespace std;
// int main() {
//     string s;
//     int n, j;
//     cin >> s >> n;
//     for (int cnt = 1; cnt < n; cnt++) {
//         string t;
//         for (int i = 0; i < s.length(); i = j) {
//             for (j = i; j < s.length() && s[j] == s[i]; j++);
//             t += s[i] + to_string(j - i);
//         }
//         s = t;
//     }
//     cout << s;
//     return 0;
// }