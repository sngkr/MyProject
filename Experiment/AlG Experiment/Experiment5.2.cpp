#include <iostream>
using namespace std;
int match[100][100];
void getMatchtable(float xb[], float yb[], float xw[], float yw[], int n) {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      match[i][j] = 0;
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (xb[i] >= xw[j] && yb[i] >= yw[j]) match[i][j] = 1;
}
int solution(int n) {
  int priority[n][n], i, j;
  int count = 0;
  while (1) {
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) {
        priority[i][j] = match[i][j];
      }
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) {
        if (priority[i][j] == 1) {
          for (int k = 0; k < n; k++)
            if (match[i][k] == 1 && k != j) priority[i][j] += 1;
          for (int k = 0; k < n; k++)
            if (match[k][j] == 1 && k != i) priority[i][j] += 1;
        }
      }
    int min = n * n;
    int indexi = 0;
    int indexj = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (min > priority[i][j] && priority[i][j] != 0) {
          min = priority[i][j];
          indexi = i;
          indexj = j;
        }
    for (int i = 0; i < n; i++) match[i][indexj] = 0;
    for (int j = 0; j < n; j++) match[indexi][j] = 0;
    int matchnum = 0;
    count++;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (match[i][j] == 1) matchnum++;
    if (matchnum == 0) break;
  }
  return count;
}
int main() {
  int k, n, i;
  cin >> k;
  for (i = 0; i < k; i++) {
    cin >> n;
    float xb[n], yb[n], xw[n], yw[n];
    for (i = 0; i < n; i++) cin >> xb[i] >> yb[i];
    for (i = 0; i < n; i++) cin >> xw[i] >> yw[i];
    getMatchtable(xb, yb, xw, yw, n);
    cout << solution(n) << endl;
  }
}
