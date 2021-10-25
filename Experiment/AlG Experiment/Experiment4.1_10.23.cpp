
//保留
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<vector<int>> LIS;
// int main() {
//   int num, lenMax = 0, idMaxLen = 0;
//   cin >> num;
//   int listnum = 0;
//   for (int i = 0, element; i < num; i++) {
//     cin >> element;
//     LIS.push_back(vector<int>(1, element));
//     if (i == 0)
//       continue;

//     for (int j = 0; j < LIS.size() - 1; j++) {
//       int len = LIS[j].size();
//       if (LIS[j][len - 1] < element) {
//         LIS[j].push_back(element);
//       }

//     }
//   }
//   vector<vector<int>> temp;
//   vector<int> result;
//   int cnt = 0;
//   int max = 0;
//   for (int i = 0; i < LIS.size(); i++) {
//     for (int j = i + 1; j < LIS.size(); j++) {
//       if (LIS[i][0] < LIS[j][0] && LIS[j].size() >= LIS[i].size() - 1) {
//         temp[cnt][0] = LIS[i][0];
//         temp[cnt].insert(temp[cnt].end(), LIS[j].begin(), LIS[j].end());
//         if (LIS[j].size() + 1 > max)
//           max = LIS[j].size() + 1;
//       }
//     }
//   }
//   cout << max << endl;
//   for (int i = 0; i < temp.size(); i++) {
//     if (temp[i].size() == max) {
//       for (auto it : temp[i])
//         cout << it << " ";
//     }
//   }

//   return 0;
// }

//保留
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <iostream>
// using namespace std;
// const int maxn = 103, INF = 0x7f7f7f7f;
// int a[maxn], f[maxn];
// int n, ans = -INF;
// int main() {
//   scanf("%d", &n);
//   for (int i = 1; i <= n; i++) {
//     scanf("%d", &a[i]);
//     f[i] = 1;
//   }
//   for (int i = 1; i <= n; i++)
//     for (int j = 1; j < i; j++)
//       if (a[j] < a[i])
//         f[i] = max(f[i], f[j] + 1);
//   for (int i = 1; i <= n; i++)
//     ans = max(ans, f[i]);
//   printf("%d\n", ans);
//   return 0;
// }
//保留
// #include <iostream>
// #include <vector>
// using namespace std;
// vector<vector<int>> LIS;
// int main() {
//   int num, lenMax = 0, idMaxLen = 0;
//   cin >> num;
//   int listnum = 0;
//   for (int i = 0, element; i < num; i++) {
//     cin >> element;
//     LIS.push_back(vector<int>(1, element));
//     if (i == 0)
//       continue;

//     for (int j = 0; j < LIS.size() - 1; j++) {
//       int len = LIS[j].size();
//       if (LIS[j][len - 1] < element) {
//         LIS[j].push_back(element);
//         // if (len + 1 > lenMax)
//         //   lenMax = len + 1;
//       }
//       //   if (LIS[j][len - 1] > element && LIS[j][len - 2] < element && len
//       >
//       //   1) {
//       //     LIS[j][len - 1] = element;
//       //   }
//       // if(LIS[j][0] < element){

//       // }
//     }
//   }
//   vector<vector<int>> temp;
//   vector<int> result;
//   int cnt = 0;
//   int max = 0;
//   for (int i = 0; i < LIS.size(); i++) {
//     for (int j = i + 1; j < LIS.size(); j++) {
//       if (LIS[i][0] < LIS[j][0] && LIS[j].size() >= LIS[i].size() - 1) {
//         temp[cnt][0] = LIS[i][0];
//         temp[cnt].insert(temp[cnt].end(), LIS[j].begin(), LIS[j].end());
//         if (LIS[j].size() + 1 > max)
//           max = LIS[j].size() + 1;
//       }
//     }
//   }
//   cout << max << endl;
//   for (int i = 0; i < temp.size(); i++) {
//     if (temp[i].size() == max) {
//       for (auto it : temp[i])
//         cout << it << " ";
//     }
//   }

//   //   for (int i = 0; i < LIS.size(); i++) {
//   //     if (lenMax == LIS[i].size()) {
//   //       cout << "\n" << lenMax << endl;
//   //       for (int j = 0; j < LIS[i].size(); j++) {
//   //         cout << LIS[i][j] << " ";
//   //       }
//   //     }
// }

// return 0;
// }
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <iostream>
// using namespace std;
// const int maxn = 103, INF = 0x7f7f7f7f;
// int a[maxn], f[maxn];
// int n, ans = -INF;
// int main() {
//   scanf("%d", &n);
//   for (int i = 1; i <= n; i++) {
//     scanf("%d", &a[i]);
//     f[i] = 1;
//   }
//   for (int i = 1; i <= n; i++)
//     for (int j = 1; j < i; j++)
//       if (a[j] < a[i])
//         f[i] = max(f[i], f[j] + 1);
//   for (int i = 1; i <= n; i++)
//     ans = max(ans, f[i]);
//   printf("%d\n", ans);
//   return 0;
// }