/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 0ms 100.00% 8MB 100.00%
// dynamic iterative programming
// O(N) O(1)
class Solution {
 public:
  int rob(vector<int>& A) {
    int sum2ago = 0, sum1ago = 0, cur = 0, n = A.size();
    for (int i = 0; i < n; ++i) {
      cur = max(sum2ago + A[i], sum1ago);
      sum2ago = sum1ago;
      sum1ago = cur;
    }
    return cur;
  }
};
