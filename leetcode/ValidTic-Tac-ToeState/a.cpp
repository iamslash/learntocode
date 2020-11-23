/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

// 0ms 100.00% 8.2MB 56.19%
// O(1) O(1)
class Solution {
 private:
  bool isWin(std::vector<std::string>& B, char c) {
    // horizontal win
    for (int y = 0; y < 3; ++y) {
      if (std::count(B[y].begin(), B[y].end(), c) == 3)
        return true;
    }
    // vertical win
    for (int x = 0; x < 3; ++x) {
      if (c == B[0][x] && c == B[1][x] && c == B[2][x])
        return true;
    }
    // diagonal win
    return (c == B[0][0] && c == B[1][1] && c == B[2][2]) ||
        (c == B[0][2] && c == B[1][1] && c == B[2][0]);
  }
 public:
  bool validTicTacToe(std::vector<std::string>& B) {
    int nx = 0;
    int no = 0;
    for (int y = 0; y < 3; ++y) {
      for (int x = 0; x < 3; ++x) {
        if (B[y][x] == 'X')
          nx++;
        else if (B[y][x] == 'O')
          no++;
      }
    }
     
    bool bx = isWin(B, 'X');
    bool bo = isWin(B, 'O');

    if (bx && bo)
      return false;
    if (bx)
      return nx == no + 1;
    if (bo)
      return nx == no;
    return nx == no + 1 || nx == no;
  }
};

int main() {
  return 0;
}
