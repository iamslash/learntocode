/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <set>

// 0ms 100.00 %
class Solution {
 private:
  std::vector<std::vector<int>> m_rslt;
  std::vector<int> m_comb;
 public:
  void solve(int k, int n) {
    // base condition
    if (m_comb.size() == k && n == 0) {
      m_rslt.push_back(m_comb);
      return;
    }
    if (m_comb.size() > k)
      return;
    
    // recursion
    int start = m_comb.empty() ? 1 : m_comb.back() + 1;
    for (int i = start; i <= 9; ++i) {
      if (n - i < 0)
        break;
      m_comb.push_back(i);
      solve(k, n - i);
      m_comb.pop_back();
    }
  }
  std::vector<std::vector<int>> combinationSum3(int k, int n) {
    // bit mask
    solve(k, n);    
    return m_rslt;
  }
};

int main() {
  // int k = 3, n = 7;
  int k = 3, n = 9;

  Solution sln;
  auto M = sln.combinationSum3(k, n);
  for (const auto& V : M) {
    for (int a : V) {
      printf("%d ", a);
    }
    printf("\n");
  }
  
  return 0;
}
