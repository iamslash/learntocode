/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// iterative way
// 0ms 100%
class Solution {
 public:
  int integerBreak(int n) {
    std::vector<int> C(n+1, 0);
    C[1] = 1;
    C[2] = 1;

    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        C[i] = std::max(C[i], std::max(j * (i-j), j * C[i-j]));
      }
    }
    return C[n];
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.integerBreak(10));
  
  return 0;
}
