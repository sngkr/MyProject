/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
 public:
  int fib(int n) {
    if (n < 2) return n;
    int n_2 = 0, n_1 = 0, rn = 1;
    for (int i = 2; i <= n; i++) {
      n_2 = n_1;
      n_1 = rn;
      rn = n_2 + n_1;
    }
    return rn;
  }
};
// @lc code=end
