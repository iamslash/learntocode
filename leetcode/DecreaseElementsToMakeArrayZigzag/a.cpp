/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 4ms 56.75% 8.5MB 100.00%
// brute force
// O(N) O(1)
class Solution {
 public:
  int movesToMakeZigzag(std::vector<int>& A) {
    std::vector<int> sum(2);
    int n = A.size();
    for (int i = 0; i < n; ++i) {
      int l = i == 0 ? 1001 : A[i-1];
      int r = i == n-1 ? 1001 : A[i+1];
      sum[i%2] += std::max(0, A[i] - std::min(l, r) + 1);
    }
    return std::min(sum[0], sum[1]);
  }
};

int main() {
  return 0;
}
