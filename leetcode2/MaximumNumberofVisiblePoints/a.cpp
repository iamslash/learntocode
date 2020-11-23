/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

// 1 / 180 = x / pi
// x * 180 / pi = 1

using namespace std;

// 732ms 94.92% 120.3MB 5.87%
// polar angle
// O(NlgN) O(N)
#define PI 3.14159265
#define MARGIN 1e-9
class Solution {
 private:
  double polarAngle(int x, int y) {
    return atan2(y, x) * 180 / PI;
  }
 public:
  int visiblePoints(vector<vector<int>>& points, int range, vector<int>& location) {
    int i, j, n = points.size(), center = 0;
    vector<double> angles;
    for (int i = 0; i < n; ++i) {
      int x = points[i][0] - location[0];
      int y = points[i][1] - location[1];
      if (x == 0 && y == 0) {
        center++;
      } else {
        double angle = polarAngle(x, y);
        if (angle < 0)
          angle += 360;
        angles.emplace_back(angle);
      }
    }
    // sliding window
    sort(angles.begin(), angles.end());
    vector<double> angles2 = angles;
    angles2.insert(angles2.end(), angles.begin(), angles.end());
    for (int i = angles.size(); i < angles2.size(); ++i) {
      angles2[i] += 360;
    }
    int ans = 0;
    for (int i = 0, j = 0; i < angles2.size(); ++i) {
      while (j < angles2.size() && (angles2[j] - angles2[i] <= range + MARGIN))
        j++;
      ans = max(ans, j - i);
    }
    return ans + center;
  }
};
