/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <numeric>

// 180ms 44.19% 28MB 100.00%
// MST(Minimum Spanning Tree)
// O(NlgN) O(N)
class Solution {
 private:
  std::vector<int> m_prnt;
  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return;
    m_prnt[a] = b;
  }
  int find(int a) {
    if (m_prnt[a] == a)
      return a;
    return m_prnt[a] = find(m_prnt[a]);
  }
 public:
  int minimumCost(int N, std::vector<std::vector<int>>& E) {
    m_prnt.resize(N);
    std::iota(m_prnt.begin(), m_prnt.end(), 0);
    int cnt = 0, sum = 0;
    for (auto& e : E)
      std::swap(e[0], e[2]);
    std::sort(E.begin(), E.end());
    for (auto& e : E) {
      int c = e[0], u = e[1], v = e[2];
      printf("c: %d, u: %d, v: %d\n", c, u, v);
      if (find(u-1) == find(v-1))
        continue;
      merge(u-1, v-1);
      cnt++;
      sum += c;
    }

    return cnt + 1 == N ? sum : -1;
  }
};

int main() {
  return 0;
}
