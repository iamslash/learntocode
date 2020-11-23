/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <numeric>

// 4ms 98.05% 9.3MB 80.00%
// DisjointSet
// O(N) O(1)
class Solution {
 private:
  std::vector<int> m_prnt;
  int find(int u) {
    if (m_prnt[u] == u)
      return u;
    return m_prnt[u] = find(m_prnt[u]);
  }
  void merge(int u, int v) {
    m_prnt[find(u)] = find(v);
  }
 public:
  bool equationsPossible(std::vector<std::string>& E) {

    m_prnt = std::vector<int>(26);
    std::iota(m_prnt.begin(), m_prnt.end(), 0);

    for (auto &s : E) {
      if (s[1] == '=')
        merge(s[0] - 'a', s[3] - 'a');
    }
    for (auto &s : E) {
      if (s[1] == '!') {
        if (find(s[0] - 'a') == find(s[3] - 'a'))
          return false;
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
