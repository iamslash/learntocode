/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 564ms 33.33% 66.6MB 33.33%
// sort
// O(NlgN) O(1)
class Solution {
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](const vector<int>& a,
                                          const vector<int>& b) {
                                         return a[0] < b[0];
                                       });
    int maxLen = 0;
    for (int i = 1; i < points.size(); ++i) {
      maxLen = max(maxLen, points[i][0] - points[i-1][0]);
    }
    return maxLen;
  }
};
