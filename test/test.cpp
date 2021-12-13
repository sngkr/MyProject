#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define P (1 << 8);
#define C (1 << 4);
bool search(vector<int>& nums, int L, int R, int min, int max) {
  int mid = (L + R) / 2;
  if (L < mid && mid < R) {
    int minL = nums[L];
    int maxR = nums[R];
    for (int i = L; i < mid; ++i) {
      if (minL > nums[i]) minL = nums[i];
    }
    if (min < minL) minL = min;
    for (int i = mid + 1; i <= R; ++i) {
      if (maxR < nums[i]) maxR = nums[i];
    }
    if (max > maxR) maxR = max;
    if (minL < nums[mid] && maxR > nums[mid])
      return true;
    else {
      if (search(nums, L, mid, minL, maxR) || search(nums, mid, R, minL, maxR))
        return true;
      else
        return false;
    }
  } else
    return false;
}

int main() {
  vector<int> temp = {1, 5, 0, 4, 1, 3};
  int n = temp.size() - 1;
  int min = temp[0];
  int max = temp[0];
  for (int i = 0; i < n / 2; ++i) {
    if (temp[i] < min) min = temp[i];
  }
  for (int i = n / 2 + 1; i < n; ++i) {
    if (temp[i] > max) max = temp[i];
  }
  if (search(temp, 0, n - 1, min, max))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  return 0;
}
