/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26]{};
        for(char c: ransomNote) --cnt[c-'a'];
        for(char c: magazine) ++cnt[c-'a'];
        return all_of(cnt, cnt + 26, [](int x){return x >= 0;});
    }
};
// @lc code=end

