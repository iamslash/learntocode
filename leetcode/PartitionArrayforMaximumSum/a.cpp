/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>


// K: 3
//         i
// A: 1 15 7 9 2 5 10
//         _
//      ____
//    ______

// 16ms 73.99% 8.8MB 100.00%
// dynamic programming
// O(N) O(N)
class Solution {
 public:
  int maxSumAfterPartitioning(std::vector<int>& A, int K) {
    int n = A.size();
    std::vector<int> C(n);
    for (int i = 0; i < n; ++i) {
      int maxnum = A[i], s = std::max(0, i - K + 1);
      // printf("i:%2d, s: %2d\n", i, s);       
      for (int j = i; j >= s; --j) {
        maxnum = std::max(maxnum, A[j]);
        int prv = j > 0 ? C[j-1] : 0;
        C[i] = std::max(C[i], prv + maxnum * (i - j + 1));
        // printf("  j: %2d, maxnum: %2d\n", j, maxnum);
      }
    }
    return C[n-1];
  }
};

int main() {
  std::vector<int> A = {1, 15, 7, 9, 2, 5, 10};
  int K = 3;

  Solution sln;
  printf("%d\n", sln.maxSumAfterPartitioning(A, K));
  
  return 0;
}
