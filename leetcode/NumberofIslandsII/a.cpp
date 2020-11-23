/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <set>
#include <numeric>

// 160ms 41.94% 26.7MB 27.35%
// Union-Find
// O(KlgHW) O(HW)
struct DisjointSet {
  std::vector<int> m_prnt;
  std::vector<int> m_rank;
  DisjointSet(int n) : m_prnt(n), m_rank(n) {
    std::iota(m_prnt.begin(), m_prnt.end(), 0);
    std::fill(m_rank.begin(), m_rank.end(), 1);
  }
  int find(int u) {
    if (u == m_prnt[u])
      return u;
    return m_prnt[u] = find(m_prnt[u]);
  }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (m_rank[u] > m_rank[v])
      std::swap(u, v);
    m_prnt[u] = v;
    if (m_rank[u] == m_rank[v])
      ++m_rank[v];
    return true;
  }
};
class Solution {
 public:
  std::vector<int> numIslands2(
      int h, int w, std::vector<std::pair<int, int>>& P) {
    std::vector<int> rslt;
    std::set<std::pair<int, int>> ust;
    DisjointSet ds(h*w);
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    int cnt = 0;
    for (auto& pr : P) {
      int y = pr.first;
      int x = pr.second;
      ust.insert({y, x});
      cnt++;
      for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w || !ust.count({ny, nx}))
          continue;
        if (ds.merge(y * w + x, ny * w + nx))
          --cnt;
      }
      rslt.push_back(cnt);
    }
    return rslt;
  }
};

// 1 1 0
// 0 0 1 
// 0 1 0
  
int main() {
  int h = 3;
  int w = 3;
  std::vector<std::pair<int, int>> P = {
    {0, 0},
    {0, 1},
    {1, 2},
    {2, 1}
  };
  Solution sln;
  auto r = sln.numIslands2(h, w, P);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
