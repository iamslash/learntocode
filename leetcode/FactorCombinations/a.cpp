/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

// 32
// 2 16
// 2 2 8
// 2 2 2 4
// 2 2 2 2 2
// 2 4 4
// 4 8
// 

// 4ms 100.00% 9MB 50.00%
// backtracking
// O(??) O(N)
class Solution {
 private:
  std::vector<std::vector<int>> m_rslt;
  std::vector<int> m_comb;
  void dfs(int n) {
    int start;
    if (m_comb.empty()) {
      start = 2;
    } else {
      start = m_comb.back();
      m_comb.push_back(n);
      m_rslt.push_back(m_comb);
      m_comb.pop_back();
    }
    int end = std::sqrt(n);
    for (int i = start; i <= end; ++i) {
      if (n % i == 0) {
        m_comb.push_back(i);
        dfs(n / i);
        m_comb.pop_back();
      }
    }
  }
 public:
  std::vector<std::vector<int>> getFactors(int n) {
    if (n < 4)
      return {};
    dfs(n);
    return m_rslt;
  }
};

int main() {
  Solution sln;
  auto r = sln.getFactors(32);
  for (auto& l : r) {
    for (int a : l)
      printf("%d ", a);
    printf("\n");
  }
  return 0;
}
