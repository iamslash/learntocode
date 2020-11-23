/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 20ms 28.57% 11.5MB 25.00%
// DFS
// O(N) O(N)
class Solution {
 private:
  void dfs(std::vector<std::vector<int>> &G, int y, int x) {
    G[y][x] = 1;
    int h = G.size(), w = G[0].size();
    int d[5] = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int ny = y + d[i];
      int nx = x + d[i+1];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w || G[ny][nx] == 1)
        continue;
      dfs(G, ny, nx);
    }
  }
 public:
  int regionsBySlashes(std::vector<std::string>& F) {
    int h = F.size(), w = F[0].size(), ans = 0;
    std::vector<std::vector<int>> G(h*3, std::vector<int>(w*3, 0));
    // upscale
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (F[y][x] == '/')
          G[y*3][x*3+2] = G[y*3+1][x*3+1] = G[y*3+2][x*3] = 1;
        if (F[y][x] == '\\')
          G[y*3][x*3] = G[y*3+1][x*3+1] = G[y*3+2][x*3+2] = 1;        
      }
    }
    h = G.size(), w = G[0].size();
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] == 0) {
          dfs(G, y, x);
          ans++;
        }
      }
    }    
    return ans;        
  }
};

int main() {

  std::vector<std::string> F = {" /", "/ "};

  Solution sln;
  printf("%d\n", sln.regionsBySlashes(F));
  
  return 0;
}
