#include <cmath>
#include <iostream>
using namespace std;
float u[100][100];
void setup(int c, float* a, float* b) {
  int i, j;
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < c; j++) {
      u[i][j] =
          sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]));
    }
  }
}
float sanjiao(int b, int c) {
  float s = 999, a[100];
  int i, j = 0;
  if ((c - b) == 2) {
    return 0;
  } else {
    for (i = b + 1; i < c; i++) {
      if (i == b + 1) {
        a[j] = sanjiao(i, c) + u[b + 1][c];
      } else if (i == c - 1) {
        a[j] = sanjiao(b, i) + u[b][c - 1];
      } else {
        a[j] = sanjiao(i, c) + sanjiao(i, b) + u[b][i] + u[i][c];
      }
      j++;
    }
    for (j = 0; j < c - b - 1; j++) {
      if (s > a[j])
        s = a[j];
    }
    return s;
  }
}
int main() {
  int k, h;
  float a[100], b[100], q[100];
  cin >> k;
  for (int i = 0, num; i < k; i++) {
    cin >> num;
    for (int j = 0; j < num; j++) {
      cin >> a[j] >> b[j];
    }
    setup(h, a, b);
    q[i] = sanjiao(0, h - 1);
  }

  for (int i = 0; i < k; i++)
    printf("%.3f\n\n", q[i]);
}