/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 0) {
      return {};
    }

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    int L, R;
    for (int i = 0; i < n; i++) {
      L = intervals[i][0], R = intervals[i][1];
      if (res.size() && L <= res.back()[1]) {
        res.back()[1] = max(res.back()[1], R);
      } else {
        res.push_back({L, R});
      }
    }
    return res;
  }
};
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         // if (intervals.size() == 0) {
//         //     return {};
//         // }
//         sort(intervals.begin(), intervals.end());
//         vector<vector<int>> merged;
//         for (int i = 0; i < intervals.size(); ++i) {
//             int L = intervals[i][0], R = intervals[i][1];
//             if (!merged.size() || merged.back()[1] < L) {
//                 merged.push_back({L, R});
//             }
//             else {
//                 merged.back()[1] = max(merged.back()[1], R);
//             }
//         }
//         return merged;
//     }
// };

// @lc code=end
