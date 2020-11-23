// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
 public:
  int m_N;
  std::vector<std::vector<int>> m_adj;
  std::vector<int> m_visited;
  std::vector<int> m_order;
  void dfs(int u) {
    m_visited[u] = 1;
    for (int v = 0; v < m_N; ++v) {
      if (m_visited[v] == 0 && m_adj[u][v] > 0)
        dfs(v);
    }
    m_order.push_back(u);
  }
  std::vector<int> findOrder(int N, const std::vector<std::pair<int, int>>& M) {
    if (N == 0)
      return m_order;

    // set member vars
    m_N = N;
    m_visited.resize(N, 0);
    m_adj.resize(N, std::vector<int>(N, 0));
    for (const auto& p : M) {
      m_adj[p.second][p.first] = 1;
    }

    // dfs all
    for (int u = 0; u < N; ++u) {
      if (m_visited[u] == 0)
        dfs(u);
    }

    // reverse
    std::reverse(m_order.begin(), m_order.end());

    // check back-edge
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (m_adj[m_order[j]][m_order[i]] == 1)
          return std::vector<int>();
      }
    }

    return m_order;
  }
};

int main() {
  int N = 4;
  // std::vector<std::pair<int, int>> M = {{1, 0}};
  std::vector<std::pair<int, int>> M = {{1, 0},
                                        {2, 0},
                                        {3, 1},
                                        {3, 2}};
  
  Solution sln;
  auto rslt = sln.findOrder(N, M);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");
  
  return 0;
}
