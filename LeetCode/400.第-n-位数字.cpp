/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */
// @lc code=start
class Solution {
 public:
  int findNthDigit(int n) {
    int d = 1, count = 9;
    while (n > (long)d * count) {
      n -= d * count;
      d++;
      count *= 10;
    }
    int index = n - 1;
    int start = (int)pow(10, d - 1);
    int num = start + index / d;
    int digitIndex = index % d;
    int digit = (num / (int)(pow(10, d - digitIndex - 1))) % 10;
    return digit;
    //     int result;
    //     int i = 1;
    //     while (i) {
    //       int temp = i;
    //       //确定几位数
    //       int digit = 0;
    //       while (temp) {
    //         digit++;
    //         temp /= 10;
    //       }
    //       temp = i;
    //       //挨个取
    //       while (digit) {
    //         int remain = pow(10, --digit);
    //         if (--n < 0) return result;
    //         result = temp / remain;
    //         temp %= remain;
    //       }
    //       i++;
    //     }
    //     return result;
  }
};

// @lc code=end
