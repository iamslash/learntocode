/* Copyright (C) 2019 by iamslash */

#include <cstdio>

#include <vector>
#include <string>

//          i
//    j
//    b a b c a
//    b b a z b
// C: 1 1 1 2 1
// r: 3
//
// multiple LIS (longest Increasing sequence)
// 16ms 60.00%
// O(MN^2) O(N)
// M : size of A
// N : size of A[i]
class Solution {
 public:
  int minDeletionSize(std::vector<std::string>& A) {
    int m = A.size();
    int n = A[0].size();
    std::vector<int> C(n, 1);
    int rslt = n - 1, k;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        for (k = 0; k < m; ++k) {
          if (A[k][j] > A[k][i])
            break;
        }
        if (k == m && C[j] + 1 > C[i])
          C[i] = C[j] + 1;
      }
      rslt = std::min(rslt, n - C[i]);
    }
    return rslt;
  }
};

int main() {
  std::vector<std::string> A = {
    "babca",
    "bbazb"
  };
  Solution sln;
  printf("%d\n", sln.minDeletionSize(A));
  return 0;
}
