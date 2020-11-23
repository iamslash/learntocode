/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/minimum-path-sum/description/

#include <cstdio>
#include <vector>
#include <limits>

// 
class Solution {
 public:
  std::vector<std::vector<int>> m_C;
  std::vector<std::vector<int>> m_B;
  int m_sizey;
  int m_sizex;
  int _trav(int y, int x) {
    // base condition
    if (y == m_sizey - 1 &&
        x == m_sizex - 1)
      return m_B[y][x];
    else if (y >= m_sizey ||
             x >= m_sizex)
      return std::numeric_limits<int>::max();
    int& r = m_C[y][x];
    if (r >= 0)
      return r;

    // recursive condition
    r = m_B[y][x] + std::min(_trav(y + 1, x), _trav(y, x + 1));
    if (r < 0)
      r = std::numeric_limits<int>::max();
    return r;
  }
  int minPathSum(std::vector<std::vector<int>>& B) {
    if (B.empty() || B[0].empty())
      return 0;
    m_sizey = B.size();
    m_sizex = B[0].size();
    m_B = B;
    m_C = std::vector<std::vector<int>>(m_sizey,
            std::vector<int>(m_sizex, -1));
    return _trav(0, 0);
  }
};

int main() {
  std::vector<std::vector<int>> B = {
    {1, 3, 1},
    {1, 5, 1},
    {4, 2, 1},
  };
  
  Solution s;
  printf("%d\n", s.minPathSum(B));
  
  return 0;
}
