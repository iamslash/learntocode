/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 4ms 73.30% 9MB 91.00%
// greedy
// O(NlgN) O(1)
class Solution {
 public:
  int videoStitching(std::vector<std::vector<int>>& C, int T) {
    std::sort(C.begin(), C.end());
    int n = C.size(), ans = 0;
    for (int i = 0, s = 0, e = 0; s < T; ++ans) {
      while (i < n && C[i][0] <= s)
        e = std::max(e, C[i++][1]);
      if (s == e)
        return -1;
      s = e;
    }
    return ans;
  }
};

int main() {
  return 0;
}
