// #include <iostream>
// #include <string>
// using namespace std;
// string source, result;
// int main() {
//   int j;
//   int max = 0;
//   getline(cin, source);
//   for (int i = 0; i < source.length(); j = 1) {
//     string temp;
//     while (1) {
//       if (i - j >= 0 && i + j <= source.length() &&
//           source[i - j] == source[i + j]) {
//         temp = source[i - j] + temp + source[i + j];
//         j++;
//       } else
//         break;
//     }
//     if (temp.length() > max) {
//       result = temp;
//       max = temp.length();
//     }
//     i = i + j;
//   }
//   cout << result << "：" << max + 1 << endl;
//   return main();
// }
#include <iostream>
using namespace std;
int dp[1010][1010];
int main() {
  string s;
  getline(cin, s);
  int len = s.length(), ans = 1;
  for (int i = 0; i < len; i++) {
    dp[i][i] = 1;
    if (i < len - 1 && s[i] == s[i + 1]) {
      dp[i][i + 1] = 1;
      ans = 2;
    }
  }
  for (int L = 3; L <= len; L++) {
    for (int i = 0; i + L - 1 < len; i++) {
      int j = i + L - 1;
      if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
        dp[i][j] = 1;
        ans = L;
      }
    }
  }
  printf("%d", ans);
  return 0;
}