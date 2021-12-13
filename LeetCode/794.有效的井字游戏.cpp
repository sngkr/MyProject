/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution {
 public:
  bool win(vector<string>& board, char ch) {
    for (int i = 0; i < 3; i++) {
      if (ch == board[i][0] && ch == board[i][1] && ch == board[i][2])
        return true;
      if (ch == board[0][i] && ch == board[1][i] && ch == board[2][i])
        return true;
    }
    if (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch)
      return true;
    if (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch)
      return true;

    return false;
  }
  bool validTicTacToe(vector<string>& board) {
    int n = board.size();
    int countx = 0;
    int counto = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == 'X') countx++;
        if (board[i][j] == 'O') counto++;
      }
    }
    if (countx != counto && countx - 1 != counto) return false;
    if (win(board, 'X') && countx - 1 != counto) return false;
    if (win(board, 'O') && counto != countx) return false;
    return true;
  }
};
// @lc code=end
