/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 16ms 99.38%
// O(8^N) O(1)
class Solution {
 private:
  int m_h;
  int m_w;
  int m_dy[8] = {-1, -1, 0, 1, 1,  1, 0,  -1};
  int m_dx[8] = { 0,  1, 1, 1, 0, -1, -1, -1};
  bool isValidPos(int y, int x) {
    return y >= 0 && y < m_h && x >= 0 && x < m_w;
  }
  void solve(std::vector<std::vector<char>>& B, int y, int x) {
    // printf("%d %d\n", y, x);
    // base
    if (!isValidPos(y, x))
      return;
    // recursion
    if (B[y][x] == 'E') {
      int cnt = 0;
      for (int i = 0; i < 8; ++i) {
        int yn = y + m_dy[i];
        int xn = x + m_dx[i];
        if (isValidPos(yn, xn) && B[yn][xn] == 'M')
          ++cnt;
      }
      if (cnt > 0) {
        B[y][x] = '0' + cnt;
      } else {
        B[y][x] = 'B';
        for (int i = 0; i < 8; ++i) {
          solve(B, y + m_dy[i], x + m_dx[i]);
        }
      }
    }
  }
 public:
  std::vector<std::vector<char>> updateBoard(
      std::vector<std::vector<char>>& B,
      std::vector<int>& C) {
    if (B.empty() || B[0].empty())
      return B;
    m_h = B.size();
    m_w = B[0].size();
    int y = C[0], x = C[1];
    if (B[y][x] == 'M') {
      B[y][x] = 'X';
      return B;
    }
    solve(B, y, x);
    return B;
  }
};

int main() {
  Solution sln;
  std::vector<std::vector<char>> B =
    {{'E', 'E', 'E', 'E', 'E'},
     {'E', 'E', 'M', 'E', 'E'},
     {'E', 'E', 'E', 'E', 'E'},
     {'E', 'E', 'E', 'E', 'E'}};  
  std::vector<int> C = {3, 0};
  B = sln.updateBoard(B, C);
  for (const auto& l : B) {
    for (int c : l) {
      printf("%c ", c);
    }
    printf("\n");
  }
  
  return 0;
}
