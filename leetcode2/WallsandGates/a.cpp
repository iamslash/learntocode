/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <map>

// 104ms 50.60% 14.8MB 58.88%
// BFS
// O(N) O(1)
#define INF 2147483647
class Solution {
 public:
  void wallsAndGates(std::vector<std::vector<int>>& G) {
    if (G.empty() || G[0].empty())
      return;
    int h = G.size();
    int w = G[0].size();
    std::queue<std::pair<std::pair<int, int>, int>> q;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] == 0)
          q.push({{y, x}, 0});
      }
    }
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    //
    while (!q.empty()) {
      auto pr = q.front(); q.pop();
      for (int i = 0; i < 4; ++i) {
        int ny = pr.first.first + dy[i];
        int nx = pr.first.second + dx[i];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
            G[ny][nx] != INF)
          continue;
        int d  = pr.second+1;
        G[ny][nx] = d;
        q.push({{ny, nx}, d});
      }
    }
  }
};

int main() {

  std::vector<std::vector<int>> G = {
    {INF, -1, 0, INF},
    {INF, INF, INF, -1},
    {INF, -1, INF, -1},
    {0, -1, INF, INF}
  };
  Solution sln;
  sln.wallsAndGates(G);

  for (auto& l : G) {
    for (int a : l) {
      printf("%d ", a);
    }
    printf("\n");
  }
  
  return 0;
}
