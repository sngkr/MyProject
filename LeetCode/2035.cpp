#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int minimumDifference(vector<int>& nums) {
  int n = nums.size() / 2;
  vector<set<int>> L(n + 1);
  for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        sum += nums[j];
        cnt++;
      } else {
        sum -= nums[j];
      }
    }
    L[cnt].insert(sum);
  }
  int ans = INT_MAX;

  for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        sum += nums[j + n];
        cnt++;
      } else {
        sum -= nums[j + n];
      }
    }
    auto it = L[cnt].upper_bound(sum);
    if (it != L[cnt].end()) {
      ans = min(ans, abs(sum - *it));
    }
    if (it != L[cnt].begin()) {
      it--;
      ans = min(ans, abs(sum - *it));
    }
  }
  return ans;
}
int main() {
  vector<int> num;
  cout << minimumDifference(num);
  return 0;
}