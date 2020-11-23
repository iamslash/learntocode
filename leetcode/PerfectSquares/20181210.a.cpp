/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

// 12
//
// C: 0 1 2 3 1 -1 -1 -1 -1 -1 -1 -1
//
class Solution {
 private:
 public:
  int numSquares(int n) {
    if (n == 0)
      return 0;
    else if (n == 1)
      return 1;
    // C[i] = min perfect square
    std::vector<int> C = std::vector<int>(n+1, std::numeric_limits<int>::max());
    C[0] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j*j <= i; ++j) {
        C[i] = std::min(C[i], C[i-j*j]+1);
        // printf("%d %d\n", i, j);
      }
    }
    
    return C[n];
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.numSquares(12));
  printf("%d\n", sln.numSquares(13));
  
  return 0;
}
