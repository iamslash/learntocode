/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// C: 1 0 1 2 1 1 7 5
// G: 0 1 0 1 0 1 0 1
// X: 3

// 36ms 90.28% 11.4MB 100.00%
// sliding window
// O(N) O(1)
class Solution {
 public:
  int maxSatisfied(std::vector<int>& C, std::vector<int>& G, int X) {
    int like = 0, part = 0, maxp = 0, n = C.size();
    for (int i = 0; i < n; ++i) {
      like += G[i] ? 0 : C[i];
      part += G[i] ? C[i] : 0;
      if (i >= X)
        part -= G[i-X] ? C[i-X] : 0;
      maxp = std::max(maxp, part);
    }
    return like + maxp;
  }
};

int main() {
  return 0;
}
