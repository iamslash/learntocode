/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 36ms 94.49% 15.2MB 66.96%
// DFS
// O(N) O(N^2)
class Solution {
 private:
  vector<vector<int>> G;
  vector<bool> seen;
  int tgt;
  double dfs(int u, int t) {
    // base
    if (u != 1 && G[u].size() == 1 || t == 0) {
      return u == tgt;
    }
    // recursion
    seen[u] = true;
    double ans = 0;
    for (int v : G[u]) {
      if (seen[v] == true)
        continue;
      ans += dfs(v, t - 1);
    }
    return ans / (G[u].size() - (u != 1));
  }
 public:
  double frogPosition(int n, vector<vector<int>>& E,
                      int t, int target) {
    if (n == 1)
      return 1.0;
    tgt = target;
    G = vector<vector<int>>(n+1);
    for (auto& e : E) {
      int u = e[0], v = e[1];
      G[u].push_back(v);
      G[v].push_back(u);
    }
    seen = vector<bool>(n+1, false);
    return dfs(1, t);
  }
};
