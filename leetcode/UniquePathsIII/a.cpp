/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 0ms 100.00%
// O(4^N) O(1)
class Solution {
 private:
  std::vector<std::vector<int>> m_G;
  int m_h;
  int m_w;
  int m_cnt_0;   // count of 0 cell
  int dfs(int y, int x, int step = 1) {
    // for (int i = 0; i < step; ++i)
    //   printf("_");
    // printf("%d, %d\n", y, x);
    
    // base condition
    if (y < 0 || y >= m_h || x < 0 || x >= m_w || m_G[y][x] == -1)
        return 0;
    if (m_G[y][x] == 2) {
      // printf("%d %d\n", step, m_cnt_0);
      return step == m_cnt_0 ? 1 : 0;
    }

    // recursion
    int rslt = 0;
    m_G[y][x] = -1;
    int dy[4] = {-1, 0, 1,  0};
    int dx[4] = { 0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int yn = y + dy[i];
      int xn = x + dx[i];
      // traverse
      rslt += dfs(yn, xn, step + 1);
    }
    m_G[y][x] = 0;

    return rslt;
  }
 public:
  int uniquePathsIII(std::vector<std::vector<int>>& G) {
    if (G.empty() ||  G[0].empty())
      return 0;

    m_G = G;
    m_h = G.size();
    m_w = G[0].size();
    
    int ys, xs;
    m_cnt_0 = 0;
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        int g = G[y][x];
        if (g == 1) {
          ys = y;
          xs = x;
        }
        if (g != -1)
         ++ m_cnt_0;
      }
    }
    return dfs(ys, xs, 1);
  }
};
int main() {
  // std::vector<std::vector<int>> G = {
  //   {1, 0, 0, 0},
  //   {0, 0, 0, 0},
  //   {0, 0, 2, -1},
  // };

  std::vector<std::vector<int>> G = {
    {1,0,0,0},
    {0,0,0,0},
    {0,0,0,2}
  };
  Solution sln;
  printf("%d\n", sln.uniquePathsIII(G));
  return 0;
}
