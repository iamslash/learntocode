/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/combination-sum/description/

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

// 9ms 99.62%
class Solution {
 public:
  std::vector<std::vector<int>> m_r;
  std::vector<int> m_c;
  void doit(std::vector<int>& v, int b, int n) {
    // base condition
    if (!n) {
      m_r.push_back(v);
      return;
    }
    // recursion
    for (int i = b; i < m_c.size() && n >= m_c[i]; ++i) {
      v.push_back(m_c[i]);
      doit(v, i, n - m_c[i]);
      v.pop_back();
    }
  }
  std::vector<std::vector<int>> combinationSum(
      std::vector<int>& c, int t) {
    m_c = c;
    std::sort(m_c.begin(), m_c.end());
    std::vector<int> v;
    doit(v, 0, t);
    return m_r;
  }
};

int main() {
  std::vector<int> v = {2, 3, 6, 7};
  int t = 7;
  
  Solution s;
  std::vector<std::vector<int>> r = s.combinationSum(v, t);

  for (auto a : r) {
    for (int b : a) {
      printf("%d ", b);
    }
    printf("\n");
  }
  
  return 0;
}
