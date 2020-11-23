/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 176ms 87.82% 18.3MB 100.00%
// brute force
// O(N) O(1)
class Solution {
 public:
  bool canDivideIntoSubsequences(std::vector<int>& A, int K) {
    int gmax = 1, lmax = 1, n = A.size();
    for (int i = 1; i < n; ++i) {
      if (A[i-1] == A[i])
        lmax++;
      else
        lmax = 1;
      gmax = std::max(gmax, lmax);
    }
    return n >= gmax * K;
  }
};

int main() {
  return 0;
}
