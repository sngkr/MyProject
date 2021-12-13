/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    for (int i = 2; i < n; i++) {
      cost[i] = min(cost[i - 2], cost[i - 1]) + cost[i];
    }
    return min(cost[n - 2], cost[n - 1]);
  }
};

// @lc code=end
