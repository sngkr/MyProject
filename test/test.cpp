#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  // while (1)
  // {

  //     int n;
  //     int i = 0, j;
  //     i = ~scanf("%d", &n);
  //     cout << i << endl;
  //     j = ~scanf("%d", &n);
  //     cout << j << endl;
  // }
  // int i= 1<<(4*1);
  // cout<<i;
  // return 0;
  vector<int> a;
  for (int i = 0, num; i < 5; i++) {
    num = i + 2;
    a.push_back(num);
  }
  for (auto &it : a) {
    it = 9;
  }
  for (auto it : a) {
    cout << it << " ";
  }
  cout << a.back();
}
