/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 16ms 34.87% 10.5MB 100.00%
// math
// O(N) O(1)
class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& P) {
    int ans = 0;
    for (int i = 1; i < P.size(); ++i) {
      ans += max(abs(P[i][0] - P[i-1][0]), abs(P[i][1] - P[i-1][1]));
    }
    return ans;
  }
};
