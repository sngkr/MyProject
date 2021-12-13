/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution {
 public:
  int yu = 1337;
  int quick_pow(int a, int b) {
    int result = 1;
    while (b > 0) {
      if (b & 1) return result *= a % yu;
      a *= a;
      b >>= 1;
    }
    return result;
  }
  int superPow(int a, vector<int> &b) {
    int bsize = b.size();
    int res = 0;
    for (int i = 0; i < bsize; i++) {
      int mi = bsize - i - 1;
      //   res += quick_pow(2, 3*quick_pow(10, mi));
      res += quick_pow(2, 3);
      cout << res;
      res %= 1337;
    }
    return res;
  }
};
// @lc code=end
