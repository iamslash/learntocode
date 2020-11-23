/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 64ms 28.27% 13.9MB 100.00%
// brute forth
// O(N) O(N)
class Solution {
 private:
  int maxDiff(std::vector<int>& V) {
    int maxv = V[0], minv = V[0];
    for (int num : V) {
      maxv = std::max(maxv, num);
      minv = std::min(minv, num);
    }
    return maxv - minv;
  }
  
 public:
  int maxAbsValExpr(std::vector<int>& X, std::vector<int>& Y) {
    int n = X.size();
    std::vector<int> A(n, 0), B(n, 0), C(n, 0), D(n, 0);
    for (int i = 0; i < n; ++i) {
      A[i] = X[i] + Y[i] + i;
      B[i] = X[i] - Y[i] + i;
      C[i] = X[i] + Y[i] - i;
      D[i] = X[i] - Y[i] - i;
    }
    return std::max(
        std::max(maxDiff(A), maxDiff(B)),
        std::max(maxDiff(C), maxDiff(D)));
  }
};

int main() {
  return 0;
}
