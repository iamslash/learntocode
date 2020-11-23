/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

// 20ms 53.29%
class Solution {
 private:
  std::vector<std::vector<int>> m_B;
  int m_h;
  int m_w;
  int m_best;

  void dfs(int y, int x) {
    // printf("%d %d\n", y, x);
    m_best++;
    m_B[y][x] += 10;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= m_h || nx < 0 || nx >= m_w ||
          m_B[ny][nx] != 1)
        continue;
      dfs(ny, nx);
    }    
  }
 public:
  int maxAreaOfIsland(std::vector<std::vector<int>>& B) {
    if (B.empty() || B[0].empty())
      return 0;
    m_B = B;
    m_h = B.size();
    m_w = B[0].size();
    int rslt = 0;
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        if (B[y][x] != 1)
          continue;
        m_best = 0;
        dfs(y, x);
        rslt = std::max(rslt, m_best);
        // printf("== %d %d %d\n", y, x, m_best);        
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<std::vector<int>> B =
      {{0,0,1,0,0,0,0,1,0,0,0,0,0},
       {0,0,0,0,0,0,0,1,1,1,0,0,0},
       {0,1,1,0,1,0,0,0,0,0,0,0,0},
       {0,1,0,0,1,1,0,0,1,0,1,0,0},
       {0,1,0,0,1,1,0,0,1,1,1,0,0},
       {0,0,0,0,0,0,0,0,0,0,1,0,0},
       {0,0,0,0,0,0,0,1,1,1,0,0,0},
       {0,0,0,0,0,0,0,1,1,0,0,0,0}};

  Solution sln;
  printf("%d\n", sln.maxAreaOfIsland(B));
  
  return 0;
}
