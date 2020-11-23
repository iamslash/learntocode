/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 16ms 92.63% 9.4MB 94.83%
// merge find
// O(N) O(N)
class Solution {
 private:
  int root(vector<int>& parent, int u) {
    if (parent[u] != u)
      parent[u] = root(parent, parent[u]);
    return parent[u];
  }
 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& E) {
    int n = E.size();
    vector<int> parent(n+1, 0), candA, candB;
    // Check the node with two parent
    for (auto& e : E) {
      if (parent[e[1]] == 0) {
        parent[e[1]] = e[0];
      } else {
        candA = {parent[e[1]], e[1]};
        candB = e;
        e[1] = 0;
      }
    }
    // Merge find
    for (int i = 1; i <= n; ++i)
      parent[i] = i;
    for (auto& e : E) {
      if (e[1] == 0)
        continue;
      int u = e[0];
      int v = e[1];
      int pu = root(parent, u);
      if (pu == v) {
        if (candA.empty())
          return e;
        return candA;
      }
      parent[v] = pu;
    }
    return candB;
  }
};
