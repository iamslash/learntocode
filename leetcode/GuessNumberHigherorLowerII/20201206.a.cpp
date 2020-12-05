/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <limits>

// recursive way
// 16ms 38.32%
class Solution {
 private:
  std::vector<std::vector<int>> m_C;
  int solve(int s, int e) {
    // base
    if (s >= e)
      return 0;

    // memoization
    int& r = m_C[s][e];
    if (r != -1)
      return r;

    // recursion
    r = std::numeric_limits<int>::max();
    for (int x = s; x <= e; ++x) {
      int t = x + std::max(solve(s, x-1), solve(x+1, e));
      r = std::min(r, t);
    }
    return r;    
  }
 public:
  int getMoneyAmount(int n) {
    m_C.resize(n+1, std::vector<int>(n+1, -1));
    return solve(1, n);
  }
};
