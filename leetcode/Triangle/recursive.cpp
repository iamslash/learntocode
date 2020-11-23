// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/triangle/description/

#include <cstdio>
#include <vector>
#include <algorithm>

recursive way
class Solution {
 public:
  std::vector<std::vector<int>> m_B;
  std::vector<std::vector<int>> m_C;
  int solve(int y, int x, int sum) {
    // base condition
    if (y == m_B.size() - 1)
      return sum + m_B[y][x];

    // memoization
    int& r = m_C[y][x];
    if (r != -1)
      return r;

    // recursion
    r = std::min(solve(y+1, x,   sum + m_B[y][x]),
                 solve(y+1, x+1, sum + m_B[y][x]));
    return r;
  }
  int minimumTotal(std::vector<std::vector<int>>& B) {
    if (B.empty())
      return 0;
    m_B = B;
    m_C = B;
    for (int y = 0; y < B.size(); ++y) {
      for (int x = 0; x < B[y].size(); ++x) {
        m_C[y][x] = -1;
      }
    }
    return solve(0, 0, 0);
  }
};
