/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//    B: 1 2 10
//       2 3 20
//       2 5 25
// evts:  0   1   2   3   4   5
//       10  45 -10 -20     -25
//  buf: 10  55  45  25  25

// 256ms 95.85% 41.9MB 100.00%
// brute force
// O(N) O(N)
class Solution {
 public:
  std::vector<int> corpFlightBookings(
      std::vector<std::vector<int>>& B, int n) {
    std::vector<int> evts(n), ans(n);
    for (auto& b : B) {
      if (b[0]-1 < n)
        evts[b[0]-1] += b[2];
      if (b[1] < n)
      evts[b[1]]   -= b[2];
    }
    int buf = 0;
    for (int i = 0; i < n; ++i) {
      buf   += evts[i];
      ans[i] = buf;
    }
    return ans;
  }
};

int main() {
  return 0;
}
