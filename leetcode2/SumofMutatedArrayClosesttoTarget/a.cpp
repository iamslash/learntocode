/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

// 32ms 38.46% 7.4MB 100.00%
// sort
// O(NlgN) O(1)
class Solution {
 public:
  int findBestValue(std::vector<int>& A, int T) {
    std::sort(A.begin(), A.end());
    int n = A.size();
    int i = 0;
    while (i < n && T > A[i] * (n-i)) {
      T -= A[i++];
    }
    if (i == n)
      return A[n-1];
    return int(std::round((T - 0.0001 / (n-i)));
  }
};
