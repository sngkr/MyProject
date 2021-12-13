/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 3) return n;
    int n_2 = 1, n_1 = 2, rn = 3;
    for (int i = 4; i <= n; i++) {
      n_2 = n_1;
      n_1 = rn;
      rn = n_1 + n_2;
    }
    return rn;
  }
};
// @lc code=end
