/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 20 ms, 99.69%
class Solution {
 public:
  int hIndex(const std::vector<int>& V) {
    int n = V.size();
    int l = 0;
    int r = n-1, m, h;
    if (n == 0)
      return 0;
    // printf("l: %d, r: %d, n: %d\n", l, r, n);
    while (l < r) {
      m = (l + r) / 2;
      h = n - m;
      if (V[m] >= h)
        r = m;
      else
        l = m + 1;
    }
    return V[l] >= n-l ? n-l : 0;        
  }
};

int main() {
  std::vector<int> V = {1, 2, 2};
  // std::vector<int> V = {0, 1, 3, 5, 6};

  Solution sln;

  printf("%d\n", sln.hIndex(V));
  
  return 0;
}
