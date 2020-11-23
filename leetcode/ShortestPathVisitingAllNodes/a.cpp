/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

// 16ms 89.47% 6.2MB 11.39%
// BFS with dynamicprog
// O(N^3) O(N^2)
class Solution {
 public:
  int shortestPathLength(std::vector<std::vector<int>>& G) {
    int n = G.size();
    int dist[1<<n][n];
    for (int i = 0; i < (1<<n); ++i)
      for (int j = 0; j < n; ++j)
        dist[i][j] = INT_MAX;
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      q.push({1 << i, i});
      dist[1 << i][i] = 0;
    }
    while (!q.empty()) {
      auto item = q.front(); q.pop();
      int bm = item.first;
      int u  = item.second;
      int d  = dist[bm][u];
      if (bm == (1 << n) - 1)
        return d;
      for (auto v : G[u]) {
        int nbm = bm | (1 << v);
        if (dist[nbm][v] > d + 1) {
          dist[nbm][v] = d + 1;
          q.push({nbm, v});
        }
      }      
    }
    return -1;
  }
};

int main() {

  // std::vector<std::vector<int>> G = {
  //   {1,2,3},{0},{0},{0}
  // };
  std::vector<std::vector<int>> G = {
    {1},{0,2,4},{1,3,4},{2},{1,2}
  };
  
  Solution sln;
  printf("%d\n", sln.shortestPathLength(G));
  
  return 0;
}
