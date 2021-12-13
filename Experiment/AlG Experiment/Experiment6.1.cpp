#include <iostream>
using namespace std;

int main() {
  char a[10][10];
  int n, m, x, y, i, j, sx, sy, x1, y1, x2, y2, min, k[100], flag[10][10] = {0};
  int tag[8][2] = {-1, 0, 0, 1, 1, 0, 0, -1, -2, 2, 2, 2, 2, -2, -2, -2};
  cin >> n;
  while (n--) {
    cin >> x >> y;
    for (i = 0; i < x; i++) {
      for (j = 0; j < y; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'S') {
          x1 = i;
          y1 = j;
        }
      }
    }
    min = 32767;
    i = 1;
    k[0] = 0;
    k[i] = -1;
    flag[x1][y1] = 1;
    while (i >= 1) {
      while (k[i] < 7) {
        k[i] = k[i] + 1;
        x2 = x1 + tag[k[i]][0];
        y2 = y1 + tag[k[i]][1];
        if (x2 >= 0 && x2 < x && y2 >= 0 && y2 < y && a[x2][y2] != 'W' &&
            i < min) {
          if (a[x2][y2] == 'X') {
            if (i < min) min = i;
          } else if (flag[x2][y2] == 0) {
            flag[x2][y2] = 1;
            x1 = x2;
            y1 = y2;
            i++;
            k[i] = -1;
          }
        }
      }
      i--;
      flag[x1][y1] = 0;
      x1 = x1 - tag[k[i]][0];
      y1 = y1 - tag[k[i]][1];
    }
    if (min < 32767) {
      cout << min << endl;
    } else {
      cout << "NO ANSWER" << endl;
    }
  }
  return 0;
}
// #include <cstring>
// #include <iostream>
// #include <vector>
// using namespace std;
// int tag[8][2] = {-1, 0, 0, 1, 1, 0, 0, -1, -2, 2, 2, 2, 2, -2, -2, -2};
// bool vis[10][10];
// int dfs(vector<vector<char>>& grid, int x, int y, int depth) {
//   int row = grid.size();
//   int col = grid[0].size();
//   if (grid[x][y] == 'X') return depth;
//   for (int i = 0; i < 8; i++) {
//     int nx = x + tag[i][0], ny = y + tag[i][1];
//     if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
//     if (vis[nx][ny] || grid[nx][ny] == 'W') continue;
//     vis[nx][ny] = true;
//     dfs(grid, nx, ny, depth + 1);
//     vis[nx][ny] = false;
//   }
//   return 0;
// }

// int main() {
//   int times;
//   cin >> times;
//   vector<vector<char>> grid;
//   while (times--) {
//     memset(vis, 0, sizeof(vis));
//     int col, row, start_x, start_y;
//     char c;
//     cin >> row >> col;
//     for (int i = 0; i < row; ++i) {
//       vector<char> temp;
//       for (int j = 0; j < col; ++j) {
//         cin >> c;
//         temp.emplace_back(c);
//         if (c == 'S') {
//           start_x = i;
//           start_y = j;
//         }
//       }
//       grid.emplace_back(temp);
//     }
//     int res = dfs(grid, start_x, start_y, 0);
//     if (res)
//       cout << res << endl;
//     else
//       cout << "No Answer" << endl;
//   }
// }