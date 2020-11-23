/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 52ms 90.82% 11.8MB 100.00%
// DFS
// O(N) O(N)
class Solution {
 private:
  void dfs(std::vector<std::vector<int>>& G,
           int y, int x, int src) {
    G[y][x] = -src;
    int d[5] = {-1, 0, 1, 0, -1};
    int h = G.size();
    int w = G[0].size();
    for (int i = 0; i < 4; ++i) {
      int ny = y + d[i];
      int nx = x + d[i+1];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w || G[ny][nx] != src)
        continue;
      dfs(G, ny, nx, src);
    }
    // check inside cell and originated it
    if (y > 0 && y < h-1 && x > 0 && x < w-1 &&
        std::abs(G[y-1][x]) == src &&
        std::abs(G[y][x+1]) == src &&
        std::abs(G[y+1][x]) == src &&
        std::abs(G[y][x-1]) == src)
      G[y][x] = src;
  }
 public:
  std::vector<std::vector<int>> colorBorder(
      std::vector<std::vector<int>>& G,
      int r0, int c0, int col) {
    int h = G.size(), w = G[0].size();
    dfs(G, r0, c0, G[r0][c0]);
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] < 0)
          G[y][x] = col;
      }
    }
    return G;
  }
};

int main() {
  return 0;
}
