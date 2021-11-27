#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define P (1 << 8);
#define C (1 << 4);
int main() {
  int a = 4;
  int b = 8 & P;
  int i = 0;
  char str[255];
  // cout << C << endl;
  cout << b << endl;
  cout <<"sizeof str：" <<sizeof(str) << endl;
  while (i < 9) {
    int j = i;
    j = i < sizeof(str) - 1;
    cout << j << endl;
    i++;
  }

  return 0;
}

// int main() {
//   // while (1)
//   // {

//   //     int n;
//   //     int i = 0, j;
//   //     i = ~scanf("%d", &n);
//   //     cout << i << endl;
//   //     j = ~scanf("%d", &n);
//   //     cout << j << endl;
//   // }
//   // int i= 1<<(4*1);
//   // cout<<i;
//   // return 0;
//   // vector<int> a;
//   // for (int i = 0, num; i < 5; i++) {
//   //   num = i + 2;
//   //   a.push_back(num);
//   // }
//   // for (auto &it : a) {
//   //   it = 9;
//   // }
//   // for (auto it : a) {
//   //   cout << it << " ";
//   // }
//   // cout << a.back();
// }
