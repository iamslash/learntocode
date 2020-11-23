/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 172ms 84.29% 32.3MB 56.83%
// dfs
// O(V+E) O(V)
class Solution {
 private:
  // 0: not visit, 1: eventual, 2: non-eventual
  std::vector<int> m_seen;
  std::vector<int> m_rslt;
  bool dfs(std::vector<std::vector<int>>& G, int u) {
    if (m_seen[u])
      return m_seen[u] == 1;
    m_seen[u] = 2;
    for (int v : G[u]) {
      if (!dfs(G, v))
        return false;
    }
    m_seen[u] = 1;
    return true;
  }
 public:
  std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& G) {
    int n = G.size();
    m_seen.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      if (dfs(G, i))
        m_rslt.push_back(i);
    }
    return m_rslt;
  }
};

int main() {
  return 0;
}
