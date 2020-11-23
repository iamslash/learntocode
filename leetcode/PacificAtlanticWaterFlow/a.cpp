/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <limits>

// 36ms 64.45%
class Solution {
 private:
  std::vector<std::vector<int>> m_M;
  int m_h;
  int m_w;
  // DFS
  void solve(int pre, int y, int x, std::vector<std::vector<bool>>& visit) {
    // base
    if (y < 0 || y >= m_h || x < 0 || x >= m_w ||
        m_M[y][x] < pre || visit[y][x])
      return;

    // recursion
    visit[y][x] = true;
    pre = m_M[y][x];

    solve(pre, y-1, x, visit);
    solve(pre, y, x+1, visit);
    solve(pre, y+1, x, visit);
    solve(pre, y, x-1, visit);    
  }
 public:
  std::vector<std::pair<int, int>> pacificAtlantic(
      std::vector<std::vector<int>>& M) {
    if (M.empty() || M[0].empty())
      return {};

    std::vector<std::pair<int, int>> rslt;
    m_M = M;
    m_h = M.size();
    m_w = M[0].size();
    std::vector<std::vector<bool>> visit_p(m_h, std::vector<bool>(m_w, false));
    std::vector<std::vector<bool>> visit_a(m_h, std::vector<bool>(m_w, false));
    
    for (int i = 0; i < m_h; ++i) {
      solve(std::numeric_limits<int>::min(), i, 0, visit_p);
      solve(std::numeric_limits<int>::min(), i, m_w-1, visit_a);
    }
    for (int i = 0; i < m_w; ++i) {
      solve(std::numeric_limits<int>::min(), 0, i, visit_p);
      solve(std::numeric_limits<int>::min(), m_h-1, i, visit_a);
    }

    // set rslt
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        if (visit_p[y][x] && visit_a[y][x])
          rslt.push_back({y, x});
      }
    }

    return rslt;
  }
};

int main() {
  std::vector<std::vector<int>> M = {
    {1, 2, 2, 3, 5},
    {3, 2, 3, 4, 4},
    {2, 4, 5, 3, 1},
    {6, 7, 1, 4, 5},
    {5, 1, 1, 2, 4},
  };

  Solution sln;
  auto rslt = sln.pacificAtlantic(M);
  for (const auto& pr : rslt) {
    printf("{%d,%d} ", pr.first, pr.second);
  }
    printf("\n");
  
  return 0;
}
