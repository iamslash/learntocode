/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <numeric>

// This is a undirected graph.
// 16ms 99.78% 10.3MB 75.56%
// DisjointSet
// O(N) O(N)
struct DisjointSet {
  std::vector<int> m_prnt;
  DisjointSet(int n) : m_prnt(n) {
    std::iota(m_prnt.begin(), m_prnt.end(), 0);
  }
  int find(int u) {
    if (u == m_prnt[u])
      return u;
    return find(m_prnt[u]);
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    m_prnt[u] = v;
    return true;
  }
};
class Solution {
 public:
  bool validTree(int n, std::vector<std::pair<int,int>>& E) {
    if (n <= 1)
      return true;
    DisjointSet ds(n);
    for (auto& pr : E) {
      int u = pr.first;
      int v = pr.second;
      // cycle
      if (!ds.merge(u, v))
        return false;
    }
    return E.size() == n - 1;
  }
};

int main() {
  // std::vector<std::pair<int,int>> E =  {{0,1}, {0,2}, {0,3}, {1,4}};
  // int n = 5;
  // std::vector<std::pair<int,int>> E =  {{0,1}, {1,2}, {2,3}, {1,3}, {1,4}};
  // int n = 5;
  // std::vector<std::pair<int,int>> E =  {{1,0}};
  // int n = 2;
  // std::vector<std::pair<int,int>> E =  {};
  // int n = 2;
  std::vector<std::pair<int,int>> E =  {{1,0}, {2,0}};
  int n = 3;
  Solution sln;
  printf("%s\n", sln.validTree(n, E) ? "true" : "false");
  
  return 0;
}
