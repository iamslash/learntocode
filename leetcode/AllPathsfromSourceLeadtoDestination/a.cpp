/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// // 92ms 33.49%
// // DFS
// // O(N) O(N)
// class Solution {
//  private:
//   bool dfs(std::unordered_map<int, std::vector<int>> &G,
//            std::vector<int> &seen, int u, int dst) {
//     // base
//     if (G[u].empty())
//       return u == dst;
//     if (seen[u] != -1)
//       return seen[u];

//     // recursion
//     seen[u] = 0;
//     for (int v : G[u]) {
//       if (!dfs(G, seen, v, dst))
//         return false;
//     }
//     return seen[u] = 1;
//   }
//  public:
//   bool leadsToDestination(int n, std::vector<std::vector<int>> &E,
//                           int src, int dst) {
//     std::unordered_map<int, std::vector<int>> G;
//     std::vector<int> seen(n, -1); // -1: not visit, 0: visiting, 1: found a path
//     for (auto &edge : E)
//       G[edge[0]].push_back(edge[1]);
//     return dfs(G, seen, src, dst);
//   }
// };

// 68ms 93.30% 25.6MB 50.00%
// DFS
// O(N) O(N)
class Solution {
 private:
  bool dfs(std::vector<std::vector<int>> &G,
           std::vector<int> &seen, int u, int dst) {
    // base
    if (G[u].empty())
      return u == dst;
    if (seen[u] != -1)
      return seen[u];

    // recursion
    seen[u] = 0;
    for (int v : G[u]) {
      if (!dfs(G, seen, v, dst))
        return false;
    }
    return seen[u] = 1;
  }
 public:
  bool leadsToDestination(int n, std::vector<std::vector<int>> &E,
                          int src, int dst) {
    std::vector<std::vector<int>> G(n);
    std::vector<int> seen(n, -1); // -1: not visit, 0: visiting, 1: found a path
    for (auto &edge : E)
      G[edge[0]].push_back(edge[1]);
    return dfs(G, seen, src, dst);
  }
};

int main() {
  return 0;
}
