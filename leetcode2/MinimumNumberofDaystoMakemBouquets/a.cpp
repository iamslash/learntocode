/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 272ms 38.86% 15.5MB 64.15%
// DFS
// O(HW) O(HW)
class Solution {
 private:
  int h, w;
  int dir[5] = {-1, 0, 1, 0, -1};
  void dfs(vector<vector<int>>& G,
           vector<vector<bool>>& visit, int y, int x) {
    visit[y][x] = true;
    for (int i = 0; i < 4; ++i) {
      int ny = y + dir[i];
      int nx = x + dir[i+1];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
          G[ny][nx] != 1 || visit[ny][nx]) {
        continue;
      }
      dfs(G, visit, ny, nx);
    }
  }
  bool disconnected(vector<vector<int>>& G) {
    vector<vector<bool>> visit(h, vector<bool>(w, false));
    int cnt = 0;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] != 1 || visit[y][x])
          continue;
        if (++cnt > 1)
          return true;
        dfs(G, visit, y, x);
      }
    }
    return cnt == 0;
  }
 public:
  int minDays(vector<vector<int>>& G) {
    h = G.size(), w = G[0].size();
    if (disconnected(G))
        return 0;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] != 1)
          continue;
        G[y][x] = 0;
        if (disconnected(G))
          return 1;
        G[y][x] = 1;
      }
    }
    return 2;        
  }
};
