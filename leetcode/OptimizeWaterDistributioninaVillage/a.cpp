/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

// 116ms 82.89% 26MB 100.00%
// kruskal algorithm
// O(ElgE) O(V)
class Solution {
 private:
  std::vector<int> m_prnt;
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    m_prnt[u] = v;
  }
  int find(int u) {
    if (u == m_prnt[u])
      return u;
    return m_prnt[u] = find(m_prnt[u]);
  }
 public:
  int minCostToSupplyWater(
      int n,
      std::vector<int>& W,
      std::vector<std::vector<int>>& P) {
    m_prnt.resize(n+1);
    std::iota(m_prnt.begin(), m_prnt.end(), 0);
    for (int u = 1; u <= n; ++u)
      P.push_back({0, u, W[u-1]});
    std::sort(P.begin(), P.end(), [](
        std::vector<int>& a,
        std::vector<int>& b) {
                return a[2] < b[2];
              });
    int ans = 0;
    for (auto& p : P) {
      int u = p[0], v = p[1];
      if (find(u) != find(v)) {
        ans += p[2];
        merge(u, v);
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
