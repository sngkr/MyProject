
// #include <iostream>
// using namespace std;

// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     string str = to_string(a + b);
//     int len = str.length();
//     for (int i = 0; i < len; i++)
//     {
//         cout << str[i];
//         if (str[i] == '-')
//             continue;
//         if ((i + 1) % 3 == len % 3 && i != len - 1)
//         //‘，’是从后面为准，通用标准
//         //3的整数倍位置加‘，’ 最后了不能加
//         //len%3 看作偏移量
//             cout << ",";
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;
// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     string str = to_string(a + b);
//     for (int i = str.length() - 3; i > 0; i -= 3)
//         str.insert(i,",");
    
//     // 负号 后面不需要 逗号
//     if(str[0]=='-' && str[1]== ',')str.erase(1,1);
//     cout<<str;
// }