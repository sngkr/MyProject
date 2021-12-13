/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    int n = temp.size();
    if (n % 2 == 0) {
    }
  }
};
// @lc code=end
