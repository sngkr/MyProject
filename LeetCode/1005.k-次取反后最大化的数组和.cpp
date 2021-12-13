/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    int sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      //   int min_n = nums[0];
      //   int index = 0;
      //   for (int j = 0; j < nums.size(); j++) {
      //     if (nums[j] < min_n) {
      //       index = j;
      //       min_n = nums[j];
      //     }
      //   }
      if (nums[i] < 0 && k > 0) {
        nums[i] = -nums[i];
        k--;
      }
      sum += nums[i];
    }

    sort(nums.begin(), nums.end());
    return sum - (k % 2 == 0 ? 0 : 2 * nums[0]);
  }
};
// @lc code=end
