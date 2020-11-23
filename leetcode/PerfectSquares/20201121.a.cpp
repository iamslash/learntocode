/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <limits>

using namespace std;

//                      i
// n: 0 1 2 3 4 5 6 7 8 9 10 11 12
// C: 0 1 2 3 1 2 3 4 2 1

// 232ms 45.65% 9.4MB 5.01%
// dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int numSquares(int n) {
    // C[i] : perfect squares of number i
    std::vector<int> C(n+1, std::numeric_limits<int>::max());
    C[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j*j <= i; ++j) {
        C[i] = std::min(C[i], C[i-j*j]+1);
      }
    }
    return C[n];
  }
};
