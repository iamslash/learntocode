/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

// DisjointSet
// O(NlgN) O(N)
class Solution {
 private:
  std::vector<int> m_prnt = std::vector<int>(101);
  int m_mergecnt = 0;
  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return;
    m_mergecnt++;
    m_prnt[b] = a;
  }
  int find(int a) {
    if (m_prnt[a] == a)
      return a;
    return m_prnt[a] = find(m_prnt[a]);
  }
 public:
  int earliestAcq(std::vector<std::vector<int>>& L, int N) {
    std::sort(L.begin(), L.end());
    std::iota(m_prnt.begin(), m_prnt.end(), 0);
    for (auto& v : L) {
      merge(v[1], v[2]);
      if (m_mergecnt == N-1)
        return v[0];
    }
    return -1;
  }
};

int main() {
  return 0;
}
