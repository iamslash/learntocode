/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// recursive way
// 0ms 100.00%
class Solution {
 private:
  std::vector<int> m_C;
  int solve(int step, int n) {
    // for (int i = 0; i < step; ++i)
    //   printf("_");
    // printf("%d\n", n);
    
    // base
    if (n <= 2)
      return 1;

    // memoization
    int& r = m_C[n];
    if (r >= 0)
      return r;

    // recursion
    r = 0;
    for (int i = 1; i < n; ++i) {
      if (n - i >= 1) 
        r = std::max(r,
                     std::max(i * (n-i), i * solve(step+1, n-i)));      
    }
    return r;
  }
 public:
  int integerBreak(int n) {
    m_C.resize(n+1, -1);
    return solve(0, n);
  }
};

