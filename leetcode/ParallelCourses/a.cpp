/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 56ms 93.06% 23.2MB 50.00%
// DFS
// O(V+E) O(V)
class Solution {
 private:
  bool dfs(const std::vector<std::vector<int>>& G,
           std::vector<int>& D,
           std::vector<int>& S,
           int u) {
    if (S[u] == 1)
      return true;
    // cycle
    if (S[u] == 0)
      return false;

    S[u] = 0;
    for (int v : G[u]) {
      if (!dfs(G, D, S, v))
        return false;
      D[u] = std::max(D[u], 1 + D[v]);
    }
    S[u] = 1;
    return true;
  }
 public:
  int minimumSemesters(int N, std::vector<std::vector<int>>& R) {
    std::vector<int> depth(N, 1);
    // -1: not visited, 0: visiting, 1: visited
    std::vector<int> vstat(N, -1);
    std::vector<std::vector<int>> G(N);
    for (auto& v : R)
      G[v[0] - 1].push_back(v[1] - 1);
    for (int i = 0; i < N; ++i)
      if (!dfs(G, depth, vstat, i))
        return -1;
    return *std::max_element(depth.begin(), depth.end());
  }
};

int main() {
  return 0;
}
