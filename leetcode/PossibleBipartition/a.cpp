/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 212ms 57.12% 59.6MB 22.31%
// dfs
// O(V+E) O(VE)
class Solution {
 private:
  std::vector<int> m_color;
  std::unordered_map<int, std::vector<int>> m_adj;
  
  bool dfs(int u, int c) {
    // base
    if (m_color[u] == c)
      return true;
    if (m_color[u] != -1)
      return false;
    m_color[u] = c;

    // recursion
    for (int v : m_adj[u]) {
      if (!dfs(v, c ^ 1))
        return false;
    }
    
    return true;
  }
 public:
  bool possibleBipartition(
      int N, std::vector<std::vector<int>>& D) {
    m_color = std::vector<int>(N+1, -1);
    for (auto V : D) {
      m_adj[V[0]].push_back(V[1]);
      m_adj[V[1]].push_back(V[0]);
    }
    for (int u = 1; u <= N; ++u) {
      if (m_color[u] != -1)
        continue;
      if (!dfs(u, 0))
        return false;
    }
    return true;
  }
};

// // Runtime Error
// // dfs
// // O(V+E) O(VE)
// class Solution {
//  private:
//   std::vector<int> m_color;
//   std::vector<std::vector<int>> m_adj;
//   bool dfs(int u, int c) {
//     if (m_color[u] != -1 && m_color[u] != c)
//       return false;
//     if (m_color[u] == c)
//       return true;
//     for (int v : m_adj[u]) {
//       if (m_color[v] == c ||
//           !dfs(v, c ^ 1))
//         false;
//     }
//     return true;
//   }
//  public:
//   bool possibleBipartition(
//       int N, std::vector<std::vector<int>>& D) {
//     std::vector<int> m_color(N+1, -1);
//     std::vector<std::vector<int>> m_adj(N+1, std::vector<int>());
//     for (auto& V : D) {
//       m_adj[V[0]].push_back(V[1]);
//       m_adj[V[1]].push_back(V[0]);
//     }
//     for (int u = 1; u <= N; ++u) {
//       if (m_color[u] == -1 && !dfs(u, 0))
//         return false;
//     }
//     return true;
//   }
// };

int main() {
  return 0;
}
