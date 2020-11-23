// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> m_adj;  // adjacency
  std::vector<int> m_order;             // order
  std::vector<int> m_visited;        // visited
  int m_N;
  void dfs(int u) {
    m_visited[u] = 1;
    for (int v = 0; v < m_N; ++v) {
      if (m_visited[v] == 0 && m_adj[u][v] > 0)
        dfs(v);
    }
    m_order.push_back(u);
  }
  bool canFinish(int N, const std::vector<std::pair<int, int>>& M) {
    if (N == 0)
      return false;
    // set member var
    m_N = N;
    m_adj = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
    m_visited = std::vector<int>(N, 0);
    for (const auto p : M) {
      m_adj[p.second][p.first] = 1;
    }
    // dfs all
    for (int i = 0; i < N; ++i) {
      if (m_visited[i] == 0)
        dfs(i);
    }
    // reverse order for topological sort
    std::reverse(m_order.begin(), m_order.end());
    // validate cycle checking back-edge
    for (int i = 0; i < N; ++i) {
      for (int j = i+1; j < N; ++j) {
        if (m_adj[m_order[j]][m_order[i]] > 0)
          return false;
      }
    }
    return true;
  }
};

int main() {
  int N = 2;
  // std::vector<std::pair<int, int>> M = {{1, 0}};
  std::vector<std::pair<int, int>> M = {{1, 0}, {0, 1}};
  Solution sln;
  printf("%s\n", sln.canFinish(N, M) ? "true" : "false");
  return 0;
}
