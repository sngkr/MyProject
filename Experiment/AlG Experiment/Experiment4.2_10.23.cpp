#include <cmath>
#include <iostream>
using namespace std;
#define MAXS 100
float D[MAXS][MAXS];
/* 求任意两点的距离 */
void init(int num, const float* x, const float* y) {
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num; j++) {
      D[i][j] = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
    }
  }
}
float find(int y, int c) {
  float s = 999, temp[100];
  int i, j = 0;
  if ((c - y) == 2) {
    return 0;
  } else {
    for (i = y + 1; i < c; i++) {
      if (i == y + 1) {
        temp[j] = find(i, c) + D[y + 1][c];
      } else if (i == c - 1) {
        temp[j] = find(y, i) + D[y][c - 1];
      } else {
        temp[j] = find(i, c) + find(y, i) + D[y][i] + D[i][c];
      }
      j++;
    }
    for (j = 0; j < c - y - 1; j++) {
      if (s > temp[j]) s = temp[j];
    }
    return s;
  }
}
int main() {
  int k, num;
  float x[MAXS], y[MAXS];
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> num;
    for (int j = 0; j < num; j++) {
      cin >> x[j] >> y[j];
    }
    init(num, x, y);
    printf("%.3f\n\n", find(0, num - 1));
  }
  return 0;
}