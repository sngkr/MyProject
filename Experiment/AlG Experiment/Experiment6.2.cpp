#include <stdio.h>

#include <iostream>
using namespace std;
int count;         //测试组数
int n[10], m[10];  //邮票种类，限制张数
int stamps[10][10];
int money[10] = {0}, tmoney[10] = {0};  // money是连续区间的上限; tmoney是过程值
bool flag;
int bestup[10];
int bestdown[10];
int longest[10];

void backtrack(int c, int t) {
  if (t == m[c]) {
    if (tmoney[c] == money[c] + 1) flag = true;
    return;
  }
  for (int i = 0; i < n[c]; i++) {
    tmoney[c] += stamps[c][i];
    if (tmoney[c] <= money[c] + 1) backtrack(c, t + 1);
    tmoney[c] -= stamps[c][i];
  }
}

int main() {
  int down, up, longg;
  cin >> count;
  for (int i = 0; i < count; i++) {
    cin >> n[i] >> m[i];
    n[i]++;
    stamps[i][0] = 0;
    for (int j = 1; j < n[i]; j++) cin >> stamps[i][j];
  }
  for (int i = 0; i < count; i++) {
    for (int j = stamps[i][1]; j <= m[i] * stamps[i][n[i] - 1]; j++) {
      money[i] = j;
      down = j;
      while (true)  //最大值为多少，不知道，需不断循环确定
      {
        flag = false;
        backtrack(i, 0);  // t代表邮票的数量
        if (flag)
          money[i]++;
        else
          break;
      }
      up = money[i];
      longg = up - down;
      if (longg > longest[i]) {
        longest[i] = longg;
        bestdown[i] = down;
        bestup[i] = up;
      } else if (longg == longest[i]) {
        if (down < bestdown[i]) {
          bestdown[i] = down;
          bestup[i] = up;
        }
      }
    }
  }
  for (int i = 0; i < count; i++) {
    cout << bestdown[i] << " " << bestup[i] << endl;
  }
  return 0;
}
