/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// K: 3
//      i
// A: 1 3 6
//    a b
// 

// 32ms 74.49% 9.7MB 73.60%
// O(NlgN) O(1)
class Solution {
 public:
  int smallestRangeII(std::vector<int>& A, int K) {
    int n = A.size();
    std::sort(A.begin(), A.end());
    int ans = A[n-1] - A[0];
    for (int i = 1; i < n; ++i) {
      int hi = std::max(A[n-1] - K, A[i-1] + K);
      int lo = std::min(A[0] + K, A[i] - K);
      ans = std::min(ans, hi - lo);
    }
    return ans;
  }
};

int main() {
  return 0;
}
