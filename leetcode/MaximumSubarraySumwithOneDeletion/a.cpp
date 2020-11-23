/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 44ms 61.82% 15MB 100.00%
// dynamic programming
// O(N) O(N)
class Solution {
 public:
  int maximumSum(std::vector<int>& A) {
    int n = A.size(), ans, locmax, glbmax;
    std::vector<int> F(n), B(n);
    locmax = glbmax = F[0] = A[0];
    for (int i = 1; i < n; ++i) {
      locmax = std::max(A[i], locmax + A[i]);
      glbmax = std::max(glbmax, locmax);
      F[i]   = locmax;
    }
    locmax = glbmax = B[n-1] = A[n-1];
    for (int j = n-2; j >= 0; --j) {
      locmax = std::max(A[j], locmax + A[j]);
      glbmax = std::max(glbmax, locmax);
      B[j]   = locmax;
    }
    ans = glbmax;
    for (int i = 1; i < n-1; ++i) {
      ans = std::max(ans, F[i-1] + B[i+1]);
    }
    return ans;
  }
};

int main() {
  return 0;
}
