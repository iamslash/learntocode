/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 24ms 22.72% 8.3MB 59.10%
// O(NlgN) O(1)
class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int lo = 1, hi = m*n;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      int cnt = 0;
      for (int i = 1; i <= m; ++i)
        cnt += std::min(mi/i, n);
      if (k > cnt)
        lo = mi + 1;
      else
        hi = mi;
    }
    return lo;
  }
};

int main() {
  // int m = 3, n = 3, k = 5;
  // int m = 2, n = 3, k = 6;
  // int m = 3, n = 1, k = 3;
  int m = 9, n = 2, k = 3;
  
  Solution sln;
  printf("%d\n", sln.findKthNumber(m, n, k));
  
  return 0;
}
