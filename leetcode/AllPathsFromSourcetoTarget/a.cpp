// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/all-paths-from-source-to-target/description/

#include <cstdio>
#include <vector>

// class Solution {
//  public:
//   std::vector<std::vector<int>> m_r;   // paths
//   std::vector<std::vector<int>> m_g;   // adj
//   std::vector<bool> m_v;  // visited
//   std::vector<int> m_p;  // path
//   void dfs(int u) {
//     // base condition
//     if (u == m_g.size() - 1) {
//       m_r.push_back(m_p);
//       return;
//     }

//     // recursion
//     for (int i = 0; i < m_g[u].size(); ++i) {
//       int v = m_g[u][i];
//       if (m_v[v])
//         continue;
//       m_p.push_back(v);
//       m_v[v] = true;
//       dfs(v);
//       m_v[v] = false;
//       m_p.pop_back();
//     }
//   }
//   std::vector<std::vector<int>> allPathsSourceTarget(
//       std::vector<std::vector<int>>& g) {
//     m_g = g;
//     m_v.resize(g.size(), false);

//     m_p.push_back(0);
//     m_v[0] = true;
//     dfs(0);

//     return m_r;
//   }
// };

#include <queue>
#include <map>

// O(N^2)
class Solution {
 public:
  std::vector<std::vector<int>> allPathsSourceTarget(
      std::vector<std::vector<int>>& g) {
    int N = g.size() - 1;
    std::vector<std::vector<int>> r;
    std::queue<std::pair<int, std::vector<int>>> q;
    std::vector<int> p(1, 0);
    q.push(std::make_pair(0, p));
    while (!q.empty()) {
      int u = q.front().first;
      std::vector<int> pp = q.front().second; q.pop();
      for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        std::vector<int> ppp = pp;
        ppp.push_back(v);
        if (v == N) {
          r.push_back(std::move(ppp));
        } else {
          q.push(std::make_pair(v, move(ppp)));
        }
      }
    }

    return r;
  }
};

int main() {
  // std::vector<std::vector<int>> g = {
  //   {1, 2},
  //   {3},
  //   {3},
  //   {},
  // };
  std::vector<std::vector<int>> g = {
    {4, 3, 1},
    {3, 2, 4},
    {3},
    {4},
    {},
  };

  Solution s;
  auto r = s.allPathsSourceTarget(g);
  for (const auto& rr : r) {
    for (int a : rr) {
      printf("%d ", a);
    }
    printf("\n");
  }

  return 0;
}
