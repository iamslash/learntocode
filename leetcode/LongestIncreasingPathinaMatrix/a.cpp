// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> m_C;  // cache
  std::vector<std::vector<int>> m_M;  // matrices
  int m_w;  // width
  int m_h;  // height
  int solve(int y, int x) {
    // printf("  y: %d, x: %d\n", y, x);

    // base condition
    // memoization
    int& rslt = m_C[y][x];
    if (rslt >= 0)
      return rslt;

    // recursion
    rslt = 0;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      // printf("    ny: %d, nx: %d\n", ny, nx);
     
      if (ny < 0 || ny >= m_h || nx < 0 || nx >= m_w)
        continue;
      // printf("    ny: %d, nx: %d, mM: %d\n", ny, nx, m_M[ny][nx]);      
      if (m_M[ny][nx] <= m_M[y][x])
        continue;
      //
      rslt = std::max(rslt, solve(ny, nx));
    }
    return ++rslt;
  }
  int longestIncreasingPath(const std::vector<std::vector<int>>& M) {
    // validate inputs
    if (M.size() == 0 || M[0].size() == 0)
      return 0;
    m_h = M.size();
    m_w = M[0].size();
    m_M = M;
    int rslt = 0;
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        m_C = std::vector<std::vector<int>>(m_h, std::vector<int>(m_w, -1));
        rslt = std::max(rslt, solve(y, x));
        // printf("----------\n");
      }
    }
    return rslt;
  }
};

int main() {
  // std::vector<std::vector<int>> M = {
  //   {9, 9, 4},
  //   {6, 6, 8},
  //   {2, 1, 1}};
  std::vector<std::vector<int>> M = {
    {7, 8, 9},
    {9, 7, 6},
    {7, 2, 3}};
  Solution sln;
  printf("%d\n", sln.longestIncreasingPath(M));
  return 0;
}
