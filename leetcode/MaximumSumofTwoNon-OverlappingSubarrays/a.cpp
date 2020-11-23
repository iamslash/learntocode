/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 4ms 95.19% 8.8MB 87.83%
// partial sum
// O(N) O(1)
class Solution {
 public:
  int maxSumTwoNoOverlap(std::vector<int>& A, int L, int M) {
    int n = A.size();
    for (int i = 1; i < n; ++i)
      A[i] += A[i-1];
    int ans = A[L + M - 1], Lmax = A[L-1], Mmax = A[M-1];
    for (int i = L + M; i < n; ++i) {
      Lmax = std::max(Lmax, A[i-M] - A[i-L-M]);
      Mmax = std::max(Mmax, A[i-L] - A[i-L-M]);
      ans = std::max({
          ans,
          Lmax + A[i] - A[i-M],
          Mmax + A[i] - A[i-L]
        });
    }
    return ans;
  }
};

int main() {
  return 0;
}
