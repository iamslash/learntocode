/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 140ms 67.00% 7.4MB 5.05%
// floyd warshall
// O(N^3) O(N^2)
class Solution {
 public:
  vector<int> countSubgraphsForEachDiameter(
      int n, vector<vector<int>>& E) {
    vector<vector<int>> G(n, vector<int>(n, 999));
    for (auto& e : E) {
      int u = e[0]-1;
      int v = e[1]-1;
      G[u][v] = G[v][u] = 1;
    }
    for (int k = 0; k < n; ++k) {
      for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
          G[u][v] = min(G[u][v], G[u][k] + G[k][v]);
        }
      }
    }
    vector<int> ans(n-1, 0);
    for (int bm = 0; bm < (1 << n); ++bm) {
      int nodeCnt = __builtin_popcount(bm);
      int edgeCnt = 0;
      int maxDist = 0;
      for (int u = 0; u < n; ++u) {
        if ((bm & (1 << u)) == 0)
          continue;
        for (int v = u + 1; v < n; ++v) {
          if ((bm & (1 << v)) == 0)
            continue;
          edgeCnt += G[u][v] == 1;
          maxDist = max(maxDist, G[u][v]);
        }
      }
      if (edgeCnt == nodeCnt - 1 && maxDist > 0) {
        ans[maxDist - 1]++;
      }
    }
    return ans;
  }
};
