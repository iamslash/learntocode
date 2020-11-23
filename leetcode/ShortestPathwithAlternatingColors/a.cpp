/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

// 20ms 84.12% 12.7MB 100.00%
// BFS
// O(E+V) O(V)
class Solution {
public:
    std::vector<int> shortestAlternatingPaths(
        int n,
        std::vector<std::vector<int>>& R,
        std::vector<std::vector<int>>& B) {
      
      std::vector<std::vector<std::pair<int, int>>> G(
          n, std::vector<std::pair<int, int>>());
      for (auto& e : R)
        G[e[0]].push_back({e[1], 0});
      for (auto& e : B)
        G[e[0]].push_back({e[1], 1});
      std::vector<std::vector<int>> dist(
          n, std::vector<int>(2, -1));

      std::queue<std::pair<int, int>> q;
      q.push({0, 0});
      q.push({0, 1});
      dist[0] = {0, 0};

      while (q.size()) {
        auto upr = q.front(); q.pop();
        int u = upr.first;
        int uc = upr.second;

        for (auto& vpr : G[u]) {
          int v = vpr.first;
          int vc = vpr.second;

          if (dist[v][vc] != -1 || uc == vc)
            continue;
          dist[v][vc] = dist[u][uc] + 1;
          q.push({v, vc});
        }
      }

      std::vector<int> ans(n);
      for (int i = 0; i < n; ++i) {
        int a = dist[i][0], b = dist[i][1];
        ans[i] = a >= 0 && b >= 0 ? std::min(a, b) : std::max(a, b);
      }
      
      return ans;
    }
};

int main() {
  return 0;
}
