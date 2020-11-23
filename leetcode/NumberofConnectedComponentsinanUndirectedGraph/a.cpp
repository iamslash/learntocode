/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <numeric>

// // 36ms 18.55% 14.4MB 38.10%
// // DFS
// // O(N) O(N)
// class Solution {
//  private:
//   std::vector<bool> m_seen;
//   std::unordered_map<int, std::vector<int>> m_G;
//   int m_n;
//   void dfs(int u) {
//     m_seen[u] = true;
//     if (m_G.count(u)) {
//       for (int v : m_G[u]) {
//         if (!m_seen[v])
//           dfs(v);
//       }
//     }
//   }
//  public:
//   int countComponents(int n, std::vector<std::pair<int, int>>& E) {
//     m_seen = std::vector<bool>(n, false);
//     m_n = n;
//     for (auto& pr : E) {
//       int u = pr.first;
//       int v = pr.second;
//       m_G[u].push_back(v);
//       m_G[v].push_back(u);
//     }
//     int r = 0;
//     for (int u = 0; u < n; ++u) {
//       if (!m_seen[u]) {
//         dfs(u);
//         ++r;
//       }
//     }
//     return r;
//   }
// };

// 46ms 100.00% 10.4MB 77.78%
// DisjointSet
// O(E) O(N)
class Solution {
 private:
  std::vector<int> m_prnt;
  int m_cnt;
  int find(int u) {
    // printf("%d\n", u);
    if (m_prnt[u] == u)
      return u;
    return m_prnt[u] = find(m_prnt[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    m_prnt[u] = v;
    --m_cnt;
  }
 public:
  int countComponents(int n, std::vector<std::pair<int, int>>& E) {
    m_cnt = n;
    m_prnt.resize(n);
    std::iota(m_prnt.begin(), m_prnt.end(), 0);
    for (auto& pr : E) {
      int u = pr.first;
      int v = pr.second;
      merge(u, v);
    }
    return m_cnt;
  }
};

int main() {
  // int n = 5;
  // std::vector<std::pair<int, int>> E = {{0, 1}, {1, 2}, {3, 4}};
  int n = 5;
  std::vector<std::pair<int, int>> E = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};

  Solution sln;
  printf("%d\n", sln.countComponents(5, E));
  
  return 0;
}
