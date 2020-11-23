/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <array>

using namespace std;

// 96ms 75.63% 15.4MB 100.00%
// BFS
// O(N) O(N)
class Solution {
 private:
  bool canRotate(vector<vector<int>>& G, int y, int x) {
    int h = G.size(), w = G[0].size();
    return y < h-1 && x < w-1 &&
             (G[y+1][x]   & 1) == 0 &&
             (G[y][x+1]   & 1) == 0 &&
             (G[y+1][x+1] & 1) == 0;
  }
  bool canGoDown(vector<vector<int>>& G, int y, int x, bool vertical) {
    int h = G.size(), w = G[0].size();
    if (vertical)
      return y < h-2 && (G[y+2][x] & 1) == 0;
    return y < h-1 &&
             (G[y+1][x]   & 1) == 0 &&
             (G[y+1][x+1] & 1) == 0;
  }
  bool canGoRight(vector<vector<int>>& G, int y, int x, bool vertical) {
    int h = G.size(), w = G[0].size();
    if (!vertical)
      return x < w-2 && (G[y][x+2] & 1) == 0;
    return x < w-1 &&
             (G[y][x+1]   & 1) == 0 &&
             (G[y+1][x+1] & 1) == 0;
  }
 public:
  int minimumMoves(vector<vector<int>>& G) {
    int h = G.size(), w = G[0].size(), cnt = 0;
    queue<array<int, 3>> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
      int n = q.size();
      while (n-- > 0) {
        auto f = q.front(); q.pop();
        if (f[0] == h - 1 && f[1] == w - 2)
          return cnt;
        if ((G[f[0]][f[1]] & (f[2] ? 2 : 4)) == 0) {
          G[f[0]][f[1]] = G[f[0]][f[1]] | (f[2] ? 2 : 4);
          if (canGoDown(G, f[0], f[1], f[2]))
            q.push({f[0]+1, f[1], f[2]});
          if (canGoRight(G, f[0], f[1], f[2]))
            q.push({f[0], f[1]+1, f[2]});
          if (canRotate(G, f[0], f[1]))
            q.push({f[0], f[1], f[2]^1});
        }
      }
      ++cnt;
    }
    return -1;
  }
};
