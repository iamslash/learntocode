/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

// 8ms 100.00% 10.2MB 86.40%
// O(1) O(N)
class DisjointSet {
 private:
  std::vector<int> m_prnt, m_rank;
 public:
  explicit DisjointSet(int n) : m_prnt(n), m_rank(n, 1) {
    std::iota(m_prnt.begin(), m_prnt.end(), 0);
  }
  int find(int u) {
    if (m_prnt[u] == u)
      return u;
    return m_prnt[u] = find(m_prnt[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (m_rank[u] > m_rank[v])
      std::swap(u, v);
    m_prnt[u] = v;
    if (m_rank[u] == m_rank[v])
      ++m_rank[v];
  }
};

class Solution {
 public:
  std::vector<int> findRedundantConnection(
      std::vector<std::vector<int>>& E) {
    DisjointSet ds(E.size());
    std::vector<int> r(2);
    for (auto& l : E) {
      if (--l[0] > --l[1])
        std::swap(l[0], l[1]);
      if (ds.find(l[0]) == ds.find(l[1])) {
        r[0] = l[0]+1;
        r[1] = l[1]+1;
      } else {
        ds.merge(l[0], l[1]);
      }
    }
    return r;
  }
};

int main() {
  // std::vector<std::vector<int>> E = {
  //   {1, 2}, {1, 3}, {2, 3}
  // };
  std::vector<std::vector<int>> E = {
    {1, 2}, {1, 3}, {3, 4}, {1, 4}, {1, 5}
  };
  Solution sln;
  auto r = sln.findRedundantConnection(E);
  printf("%d %d\n", r[0], r[1]);
  
  return 0;
}
