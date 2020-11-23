/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <limits>

// iterative way
// 12ms 54.51
class Solution {
 public:
  int getMoneyAmount(int n) {
    std::vector<std::vector<int>> C(n+1, std::vector<int>(n+1, 0));
    for (int j = 2; j <= n; ++j) {
      for (int i = j-1; i > 0; --i) {
        int gmin = std::numeric_limits<int>::max();
        for (int k = i+1; k < j; ++k) {
          int lmax = k + std::max(C[i][k-1], C[k+1][j]);
          gmin = std::min(gmin, lmax);
        }
        C[i][j] = i+1 == j ? i : gmin;
      }
    }
    return C[1][n];
  }
};


// iterative way

int main() {
  Solution sln;
  printf("%d\n", sln.getMoneyAmount(10));
  
  return 0;
}
