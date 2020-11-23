/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 0ms 100.00% 9.2MB 99.99%
// iterative dynamic programming
// O(N) O(1)
class Solution {
 private:
  int maxRob(vector<int>& A, int lo, int hi) {
    int sum2ago = 0, sum1ago = 0, cur = 0;
    for (int i = lo; i <= hi; ++i) {
      cur = max(sum2ago + A[i], sum1ago);
      sum2ago = sum1ago;
      sum1ago = cur;
    }
    return cur;
  }
 public:
  int rob(vector<int>& A) {
    int n = A.size();
    if (n == 1)
      return A[0];
    return max(maxRob(A, 0, n-2), maxRob(A, 1, n-1));
  }
};
