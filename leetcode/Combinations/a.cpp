/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/combinations/description/

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> m_r; // result
  std::vector<int> m_c;  // combi
  int m_n;
  int m_k;
  void _solve(int start) {
    // base condition
    if (m_c.size() == m_k) {
      m_r.push_back(m_c);
      return;
    }

    // recursion
    for (int i = start; i <= m_n; ++i) {
      m_c.push_back(i);
      _solve(i+1);
      m_c.pop_back();
    }
  }
  std::vector<std::vector<int>> combine(int n, int k) {
    m_n = n;
    m_k = k;
    _solve(1);
    return m_r;
  }
};

int main() {
  Solution s;

  auto r = s.combine(4, 2);
  for (auto rr : r) {
    for (int a : rr) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}
