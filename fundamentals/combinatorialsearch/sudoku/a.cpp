/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 8ms 80.18%
// O(2^WH) O(1)
class Solution {
 private:
  int m_h;
  int m_w;
  std::pair<int, int> getEmptySlot(std::vector<std::vector<char>>& B) {
    for (int y = 0; y < m_h; ++y)
      for (int x = 0; x < m_w; ++x)
        if (B[y][x] == '.')
          return {y, x};
    return {-1,-1};
  }
  bool usedInRow(std::vector<std::vector<char>>& B, int y, char c) {
    for (int x = 0; x < m_w; ++x)
      if (B[y][x] == c)
        return true;
    return false;
  }
  bool usedInCol(std::vector<std::vector<char>>& B, int x, char c) {
    for (int y = 0; y < m_h; ++y)
      if (B[y][x] == c)
        return true;
    return false;
  }
  bool usedInBox(std::vector<std::vector<char>>& B, int box_start_row, int box_start_col, char c) {
    for (int y = 0; y < 3; ++y)
      for (int x = 0; x < 3; ++x)
        if (B[box_start_row + y][box_start_col + x] == c)
          return true;
    return false;    
  }
  bool isPlaceable(std::vector<std::vector<char>>& B, int y, int x, char c) {
    int box_start_row = y - y % 3;
    int box_start_col = x - x % 3;
    return !usedInRow(B, y, c) &&
        !usedInCol(B, x, c) &&
        !usedInBox(B, box_start_row, box_start_col, c) &&
        B[y][x] == '.';

  }
  bool solve(std::vector<std::vector<char>>& B) {
    auto pr = getEmptySlot(B);
    int y = pr.first; int x = pr.second;
    if (y == -1 && x == -1)
      return true; // done
    for (int num = 1; num <= 9; ++num) {
      char c = num + '0';
      if (isPlaceable(B, y, x, c)) {
        B[y][x] = c;
        if (solve(B))
          return true;
        B[y][x] = '.';
      }
    }
    return false;
  }  
 public:
  void solveSudoku(std::vector<std::vector<char>>& B) {
    m_h = B.size();
    m_w = B[0].size();
    solve(B);
  }
};

int main() {

    std::vector<std::vector<char>> B = {
      {'3', '.', '6', '5', '.', '8', '4', '.', '.'},
      {'5', '2', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '8', '7', '.', '.', '.', '.', '3', '1'},
      {'.', '.', '3', '.', '1', '.', '.', '8', '.'},
      {'9', '.', '.', '8', '6', '3', '.', '.', '5'},
      {'.', '5', '.', '.', '9', '.', '6', '.', '.'},
      {'1', '3', '.', '.', '.', '.', '2', '5', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '7', '4'},
      {'.', '.', '5', '2', '.', '6', '3', '.', '.'}
  };
  Solution sln;
  sln.solveSudoku(B);

  for (const auto& l : B) {
    for (char c : l) {
      printf("%c ", c);
    }
    printf("\n");
  }
  
  return 0;
}
