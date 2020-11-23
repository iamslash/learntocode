/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

class Solution {
 public:
  int nthSuperUglyNumber(int n, std::vector<int>& P) {
    std::vector<int> idx(P.size(), 0);  // idx[i] : ugl index which was made with P[i]
    std::vector<int> ugl(n, std::numeric_limits<int>::max());
    ugl[0] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < P.size(); ++j) {
        ugl[i] = std::min(ugl[i], ugl[idx[j]] * P[j]);
      }
      for (int j = 0; j < P.size(); ++j) {
        if (ugl[i] == ugl[idx[j]] * P[j])
          idx[j]++;
      }
    }
    return ugl[n-1];
  }
};

int main() {
  int n = 12;
  std::vector<int> P = {2, 7, 13, 19};
  Solution sln;
  printf("%d\n", sln.nthSuperUglyNumber(n, P));
  return 0;
}
