/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution {
 public:
  int maxPower(string s) {
    int n = s.size();
    int maxN = 1;

    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1]) {
        cnt++;
        maxN = max(maxN, cnt);
      } else
        cnt = 1;
    }
    return maxN;
  }
};
// @lc code=end
