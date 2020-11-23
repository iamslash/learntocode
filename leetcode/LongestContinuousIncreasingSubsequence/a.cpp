/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 16ms 75.83% 9.5MB 23.11%
// O(N) O(1)
class Solution {
 public:
  int findLengthOfLCIS(std::vector<int>& V) {
    if (V.empty())
      return 0;
    int ans = 1, n = V.size(), cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (V[i-1] >= V[i])
        cnt = 0;
      ans = std::max(ans, ++cnt);
    }
    return ans;
  }
};

int main() {
  return 0;
}
