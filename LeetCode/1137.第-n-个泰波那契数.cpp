/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
 public:
  int tribonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    int n_3 = 0, n_2 = 0, n_1 = 1, rn = 1;
    for (int i = 3; i <= n; i++) {
      n_3 = n_2;
      n_2 = n_1;
      n_1 = rn;
      rn = n_1 + n_2 + n_3;
    }
    return rn;
  }
};
// @lc code=end
