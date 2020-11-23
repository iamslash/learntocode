/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/unique-paths-ii/description/

#include <cstdio>
#include <vector>

// 0ms 100%
class Solution {
 public:
  std::vector<std::vector<int>> m_C;
  std::vector<std::vector<int>> m_B;
  int m_sizey;
  int m_sizex;
  int _trav(int y, int x) {
    // base condition
    if (y == m_sizey - 1 &&
        x == m_sizex - 1 &&
        m_B[y][x] == 0)
      return 1;
    else if(y >= m_sizey ||
            x >= m_sizex ||
            m_B[y][x] == 1)
      return 0;
    int& r = m_C[y][x];
    if (r >= 0)
      return r;      

    // recursive condition
    r = 0;
    r += _trav(y+1, x) + _trav(y, x+1);
    
    return r;
  }
  int uniquePathsWithObstacles(std::vector<std::vector<int>>& B) {
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
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0},
  };
  
  Solution s;
  printf("%d\n", s.uniquePathsWithObstacles(B));
  
  return 0;
}
