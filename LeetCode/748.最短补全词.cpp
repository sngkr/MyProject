/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
// class Solution {
//  public:
//   string shortestCompletingWord(string licensePlate, vector<string>& words) {
//     string res;
//     unordered_map<char, int> temp;
//     for (int i = 0; i < licensePlate.size(); i++) {
//       if (isalpha(licensePlate)[i]) temp[tolower(licensePlate[i])]++;
//     }
//     sort(words.begin(), words.end());
//     for (int i = 0; i < words.size(); i++) {
//       unordered_map<char, int> maybe;
//       for (int j = 0; j < words[i].size(); j++) {
//         maybe[words[i][j]]++;
//       }
//       int flag = 0;
//       for (int j = 0; j < words[i].size(); j++) {
//         if (temp[words[i][j]] == maybe[words[i][j]])
//           flag = 1;
//         else
//           flag = 0;
//       }
//       if (flag) {
//         if (res.size() > words[i] || res.empty()) {
//           res = words[i];
//         }
//       }
//     }
//     return res;
//   }
// };
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        array<int, 26> cnt{};
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                ++cnt[tolower(ch) - 'a'];
            }
        }
        int idx = -1;
        for (int i = 0; i < words.size(); ++i) {
            array<int, 26> c{};
            for (char ch : words[i]) {
                ++c[ch - 'a'];
            }
            bool ok = true;
            for (int j = 0; j < 26; ++j) {
                if (c[j] < cnt[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && (idx < 0 || words[i].length() < words[idx].length())) {
                idx = i;
            }
        }
        return words[idx];
    }
};

// @lc code=end
