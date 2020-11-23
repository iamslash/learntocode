/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

// * if `j - i == k`
//   * `T_{k} = (sum[n-k+1][n] - sum[1][k]) * 2^{k-1}`

// 148ms 58.59% 27MB 64.84%
// sort
// O(NlgN) O(1)
#define MOD 1000000007
class Solution {
 public:
  int sumSubseqWidths(vector<int>& A) {
    sort(A.begin(), A.end());
    int n = A.size(), l = 0, r = n-1;
    int lsum = 0, rsum = 0;
    int64_t d = 1, ans = 0;
    while (l < n) {
      lsum += A[l++];
      rsum += A[r--];
      ans = (ans + (rsum - lsum) * d) % MOD;
      d = (d * 2) % MOD;
    }
    return ans;
  }
};
