/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 708ms 97.31% 135MB 100.00%
// bridge
// O(E+V) O(V)
class Solution {
 private:
  // return the smallest order of the node whose root is u and parent
  // of u is p.
  int dfs(std::vector<std::vector<int>>& G,
          int& counter,
          std::vector<int>& found,
          std::vector<std::vector<int>>& ans,
          int u, int p) {
    // base
    found[u] = counter++;
    int r = found[u];

    // recursion
    for (auto& v : G[u]) {
      if (v == p)
        continue;
      if (found[v] == -1) {
        int minord = dfs(G, counter, found, ans, v, u);
        if (minord > found[u])
          ans.push_back({u, v});
        r = std::min(r, minord);
      } else {
        r = std::min(r, found[v]);
      }
    }
    return r;
  }
 public:
  std::vector<std::vector<int>> criticalConnections(
      int n, std::vector<std::vector<int>>& E) {
    std::vector<std::vector<int>> G(n);
    int counter = 0;
    std::vector<int> found(n, -1);
    std::vector<std::vector<int>> ans;
    // set G
    for (auto& v : E) {
      G[v[0]].push_back(v[1]);
      G[v[1]].push_back(v[0]);
    }
    dfs(G, counter, found, ans, 0, 0);
    return ans;
  }
};

int main() {
  return 0;
}
