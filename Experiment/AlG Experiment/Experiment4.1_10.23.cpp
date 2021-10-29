#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0, num; i < N; i++) {
    cin >> num;
    vector<int> result;
    vector<int> temp;
    for (int j = 0, element; j < num; j++) {
      cin >> element;
      /*特殊处理第一个元素 ，或者初始化的时候放入一个
      很大的元素。
      */
      if (j == 0) {
        result.push_back(element);
        // temp = result;
        temp.push_back(element);
        continue;
      }
      /* 元素大于result的最后一个元素的话，放在result后面
      原则：result一旦更新，temp也要更新，
      优化：这种情况不一定要全部拷贝过去，与result一样
      push_back即可
       */
      if (element > result.back()) {
        result.push_back(element);
        // temp = result;
        temp.push_back(element);
      }
      /*需要将元素放进求得序列中时，只能操作temp向量！！;
      优化：有序序列采用二分更快，但是懒。
       */
      if (element < temp.back()) {
        for (auto &it : temp) {
          if (it > element) {
            it = element;
            break;
          }
        }
      }
      /*
      原理：
      当temp的最后一个元素也被更改，说明该此时temp中的
      递增序列比result向量中的更有潜力。
      注意：
      因为不知道temp中哪些元素被更改过了，所以不能像前
      面那样优化拷贝，只能将temp全部拷贝到result中。
       */
      if (temp.back() != result.back()) result = temp;
    }
    cout << "\n" << result.size() << endl;
    for (auto it : result) {
      cout << it << " ";
    }
    cout << "\n\n";
  }
  return 0;
}
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
//       //   if (LIS[j][len - 1] > element && LIS[j][len - 2] < element &&
//       len
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