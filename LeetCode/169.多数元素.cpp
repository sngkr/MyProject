/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    // unordered_map<int, int> temp;
    // for (int i = 0; i < nums.size(); i++) {
    //   temp[nums[i]]++;
    //   if (temp[nums[i]] > nums.size() / 2) return nums[i];
    // }
    // return -1;
    // sort(nums.begin(), nums.end());
    // return nums[nums.size()/2];

    int candidate = -1;
    int count = 0;
    for (int num : nums) {
      if (num == candidate)
        ++count;
      else if (--count < 0) {
        candidate = num;
        count = 1;
      }
    }
    return candidate;
  }
};
// @lc code=end
