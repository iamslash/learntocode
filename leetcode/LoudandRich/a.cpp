/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 96ms 95.35% 31.8MB 72.12%
// O(N) O(N)
class Solution {
 private:
  std::unordered_map<int, std::vector<int>> m_adj;
  std::vector<int> m_rst;
  int dfs(int u, std::vector<int>& Q) {
    if (m_rst[u] >= 0)
      return m_rst[u];
    m_rst[u] = u;
    for (int v : m_adj[u]) {
      if (Q[m_rst[u]] <= Q[dfs(v, Q)])
        continue;
      m_rst[u] = m_rst[v];
    }
    return m_rst[u];
  }
 public:
  std::vector<int> loudAndRich(std::vector<std::vector<int>>& R,
                               std::vector<int>& Q) {
    for (auto& rich : R)
      m_adj[rich[1]].push_back(rich[0]);
    m_rst = std::vector<int>(Q.size(), -1);
    for (int i = 0; i < Q.size(); ++i)
      dfs(i, Q);
    return m_rst;
  }
};

int main() {
  return 0;
}
