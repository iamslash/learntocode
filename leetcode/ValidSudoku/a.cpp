/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/valid-sudoku/description/

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<int> m_row;
  std::vector<int> m_col;
  std::vector<std::vector<int>> m_cel;
  bool isok(std::vector<std::vector<char>>& B, int y, int x, int n) {
    // check row
    if (m_row[y] & (1 << n))
      return false;
    m_row[y] |= (1 << n);

    // check col
    if (m_col[x] & (1 << n))
      return false;
    m_col[x] |= (1 << n);

    // check cel
    int yy = y / 3;
    int xx = x / 3;
    if (m_cel[yy][xx] & (1 << n))
      return false;
    m_cel[yy][xx] |= (1 << n);

    // printf("y:%d x:%d n:%d yy:%d xx:%d\n", y, x, n, yy, xx);

    return true;
  }
  bool isValidSudoku(std::vector<std::vector<char>>& B) {
    m_row = std::vector<int>(9, 0);
    m_col = std::vector<int>(9, 0);
    m_cel = std::vector<std::vector<int>>(3, std::vector<int>(3, 0));
    for (int i = 0; i < B.size(); ++i) {
      for (int j = 0; j < B[0].size(); ++j) {
        if (B[i][j] == '.')
          continue;
        if (!isok(B, i, j, B[i][j] - '0'))
          return false;
      }
    }
    return true;
  }
};

int main() {
  std::vector<std::vector<char>> B = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  // std::vector<std::vector<char>> B = {
  //   {'8','3','.','.','7','.','.','.','.'},
  //   {'6','.','.','1','9','5','.','.','.'},
  //   {'.','9','8','.','.','.','.','6','.'},
  //   {'8','.','.','.','6','.','.','.','3'},
  //   {'4','.','.','8','.','3','.','.','1'},
  //   {'7','.','.','.','2','.','.','.','6'},
  //   {'.','6','.','.','.','.','2','8','.'},
  //   {'.','.','.','4','1','9','.','.','5'},
  //   {'.','.','.','.','8','.','.','7','9'}
  // };
  
  Solution s;
  printf("%s\n", s.isValidSudoku(B) ? "true" : "false");
  return 0;
}
