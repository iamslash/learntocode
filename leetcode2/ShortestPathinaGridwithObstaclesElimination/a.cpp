/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// 352ms 29.22% 59.6MB 12.85%
// BFS
// O(HW) O(HW)
class Solution {
 public:
  int shortestPath(vector<vector<int>>& G, int k) {
    int dirs[5] = {-1, 0, 1, 0, -1};
    int h = G.size(), w = G[0].size();
    queue<vector<int>> q;
    q.push({0, 0, 0});
    vector<vector<vector<bool>>> visit(
        h, vector<vector<bool>>(
            w, vector<bool>(
                h*w, false)));
    visit[0][0][0] = true;
    int step = 0;
    while (q.size()) {
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        auto f = q.front(); q.pop();
        int y = f[0], x = f[1], z = f[2];
        if (y == h - 1 && x == w - 1)
          return step;
          // printf("z: %d, y: %d, x: %d\n", z, y, x);
        for (int i = 0; i < 4; ++i) {
          int ny = y + dirs[i], nx = x + dirs[i+1];
          if (ny < 0 || ny >= h || nx < 0 || nx >= w)
            continue;
          int nz = z + G[ny][nx];
          if (nz > k || visit[ny][nx][nz])
            continue;
          visit[ny][nx][nz] = true;
          q.push({ny, nx, nz});          
        }
      }
      step++;
    }
    return -1;
  }
};
