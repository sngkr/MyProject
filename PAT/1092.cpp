#include <iostream>
using namespace std;

int main()
{
    int str[256] = {0};
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
    {
        str[a[i]]++;
    }
    int no = 0; 
    for (int i = 0; i < b.length(); i++)
    {
        if (str[b[i]] > 0)
            str[b[i]]--;
        else
            no++;
    }

    if (no == 0)
        printf("Yes %d", a.length() - b.length());
    else
        printf("No %d", no);

    return 0;
}

// #include <iostream>
// using namespace std;
// int book[256];
// int main() {
//     string a, b;
//     cin >> a >> b;
//     for (int i = 0; i < a.length(); i++)
//         book[a[i]]++;
//     int result = 0;
//     for (int i = 0; i < b.length(); i++) {
//         if (book[b[i]] > 0)
//             book[b[i]]--;
//         else
//             result++;
//     }
//     if(result != 0)
//         printf("No %d", result);
//     else
//         printf("Yes %d", a.length() - b.length());
//     return 0;
// }