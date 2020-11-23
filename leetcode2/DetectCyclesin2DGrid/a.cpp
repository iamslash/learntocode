/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 676ms 64.32% 93.7MB 36.82%
// DFS
// O(HW) O(HW)
class Solution {
 private:
  int dir[5] = {-1, 0, 1, 0, -1};
  int dfs(vector<vector<char>>& G,
          vector<vector<bool>>& visit,
          int y, int x, int py, int px) {
    int h = G.size(), w = G[0].size();
    visit[y][x] = true;
    for (int i = 0; i < 4; ++i) {
      int ny = y + dir[i];
      int nx = x + dir[i+1];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
          G[ny][nx] != G[y][x] || (ny == py && nx == px)) {
        continue;
      }
      if (visit[ny][nx] || dfs(G, visit, ny, nx, y, x)) {
        return true;
      }
    }
    return false;
  }
 public:
  bool containsCycle(vector<vector<char>>& G) {
    int h = G.size(), w = G[0].size();
    vector<vector<bool>> visit(h, vector<bool>(w, false));
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (visit[y][x]) {
          continue;
        }
        if (dfs(G, visit, y, x, -1, -1)) {
          return true;
        }
      }
    }
    return false;
  }
};
