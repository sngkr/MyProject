#include <iostream>
using namespace std;

int q[100][100];
int p[100][100];
int zc(int a[100], int n, int s, int v) {
  int x = 0, i, k = 0, l = 0;
  if (s == 0) {
    x = 1;
  } else {
    for (i = 0; i < s; i++) {
      if (a[s] > a[i]) {
        if (x - 1 < zc(a, n, i, v)) {
          x = zc(a, n, i, v) + 1;
          q[v][s] = i;
          l = 5;
        }
      }
    }
  }
  if (l == 0) {
    x = 1;
  }
  return x;
}
void shuchu(int a[100], int v, int n) {
  int i, z, x = 0;
  for (i = 0; i < n; i++) {
    if (x < zc(a, n, i, v)) {
      x = zc(a, n, i, v);
      z = i;
    }
  }
  cout << x << endl;
  for (i = 0; i < x; i++) {
    p[v][i] = z;
    z = q[v][z];
  }
  for (i = 0; i < x; i++) {
    cout << a[p[v][x - i - 1]] << " ";
  }
}
int main() {
  int b[100][100];
  int c, a[100], i, j, s;
  cin >> c;
  for (i = 0; i < c; i++) {
    cin >> a[i];
    for (j = 0; j < a[i]; j++) {
      cin >> b[i][j];
    }
  }
  for (i = 0; i < c; i++) {
    for (j = 0; j < 100; j++) {
      q[i][j] = 0;
      p[i][j] = 0;
    }
    shuchu(b[i], i, a[i]);
    cout << endl;
    cout << endl;
  }
  return 0;
}