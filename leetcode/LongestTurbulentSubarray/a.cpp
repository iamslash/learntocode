/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 108ms 77.90% 13.4MB 29.05%
// dynamic programming
// O(N) O(1)
class Solution {
 public:
  int maxTurbulenceSize(std::vector<int>& A) {
    int best = 0, cand = 0, n = A.size();

    for (int i = 0; i < n; ++i) {
      if (i >= 2 && ((A[i-2] > A[i-1] && A[i-1] < A[i]) ||
                     (A[i-2] < A[i-1] && A[i-1] > A[i]))) {
        cand++;
      } else if (i >= 1 && A[i-1] != A[i]) {
        cand = 2;
      } else {
        cand = 1;
      }
      best = std::max(best, cand);
    }
      
    return best;
  }
};

int main() {
  return 0;
}
