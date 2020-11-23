/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cmath>

using namespace std;

// 0ms 100.00% 5.9MB 100.00%
// math
// O(N) O(1)
class Solution {
 public:
  double angleClock(int H, int M) {
    double mAng = M * 6;
    double hAng = H * 30 + mAng / 12;
    double ans = fabs(mAng - hAng);
    if (ans > 180.0) {
      return 360.0 - ans;
    }
    return ans;
  }
};
