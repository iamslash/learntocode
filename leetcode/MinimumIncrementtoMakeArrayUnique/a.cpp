/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 96ms 28.65% 11.8MB 72.83%
// sort
// O(NlgN) O(1)
class Solution {
 public:
  int minIncrementForUnique(std::vector<int>& A) {
    std::sort(A.begin(), A.end());
    int n = A.size(), ans = 0;
    for (int i = 1; i < n; ++i) {
      if (A[i-1] >= A[i]) {
        int d = A[i-1] - A[i] + 1;
        A[i] += d;
        ans  += d;
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
