/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

// 40ms 97.95% 13.5MB 100.00%
// BFS
// O(N) O(N)
class Solution {
 public:
  int maxDistance(std::vector<std::vector<int>>& G) {
    int step = 0, h = G.size(), w = G[0].size();
    std::queue<std::pair<int, int>> q;
    int d[5] = {-1, 0, 1, 0, -1};
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] != 1)
          continue;
        for (int i = 0; i < 4; ++i) {
          int ny = y + d[i], nx = x + d[i+1];
          if (ny < 0 || ny >= h || nx < 0 || nx >= w || G[ny][nx])
            continue;
          G[ny][nx] = 2;
          q.push({ny, nx});
        }
      }
    }
    while (q.size()) {
      step++;
      int qsize = q.size();
      while (qsize-- > 0) {
        auto pr = q.front(); q.pop();
        int y = pr.first, x = pr.second;
        for (int i = 0; i < 4; ++i) {
          int ny = y + d[i], nx = x + d[i+1];
          if (ny < 0 || ny >= h || nx < 0 || nx >= w || G[ny][nx])
            continue;
          G[ny][nx] = 2;
          q.push({ny, nx});
        }
      }
    }

    return step == 0 ? -1 : step;
  }
};

int main() {
  return 0;
}
