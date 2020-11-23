/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// // 64ms 5.54% 22.7MB 5.30%
// // BFS
// // O(V+E) O(V)
// class Solution {
//  private:
//   std::unordered_map<int, std::unordered_set<int>> m_G;
//   std::vector<int> m_colors;
//   bool bfs(int src) {
//     m_colors[src] = 1;
//     std::queue<int> q;
//     q.push(src);
//     while (!q.empty()) {
//       int u = q.front(); q.pop();
//       // printf("%d\n", u);
//       // self cycle
//       if (m_G[u].count(u))
//         return false;
//       for (int v : m_G[u]) {
//         if (m_colors[v] == -1) {
//           m_colors[v] = 1 - m_colors[u];
//           q.push(v);
//         } else if (m_colors[v] == m_colors[u]) {
//           return false;
//         }
//       }
//     }
//     return true;
//   }
//  public:
//   bool isBipartite(std::vector<std::vector<int>>& G) {
//     int n = G.size();
//     for (int u = 0; u < n; ++u) {
//       for (int v : G[u]) {
//         // printf("%d %d\n", u, v);
//         m_G[u].insert(v);
//       }
//     }
//     m_colors = std::vector<int>(n, -1);
//     for (auto& pr : m_G) {
//       int src = pr.first;
//       if (m_colors[src] == -1 && bfs(src) == false)
//         return false;
//     }
//     return true;
//   }
// };


// 28ms 79.46% 11.5MB 89.39%
// DFS
// O(V+E) O(N)
class Solution {
 private:
  bool dfs(std::vector<std::vector<int>>& G, std::vector<int>& C, int u, int c) {
    C[u] = c;
    for (auto v : G[u]) {
      if (C[v] == c)
        return false;
      if (C[v] == 0 && !dfs(G, C, v, -c))
        return false;
    }
    return true;
  }
 public:
  bool isBipartite(std::vector<std::vector<int>>& G) {
    int n = G.size();
    std::vector<int> C(n, 0);
    for (int i = 0; i < n; ++i) {
      if (C[i] == 0 && !dfs(G, C, i, 1))
        return false;
    }
    return true;
  }
};

int main() {
  // std::vector<std::vector<int>> G = {{1,3}, {0,2}, {1,3}, {0,2}};
  std::vector<std::vector<int>> G = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
  Solution sln;
  printf("%s\n", sln.isBipartite(G) ? "true" : "false");  
  return 0;
}
