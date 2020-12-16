/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 28ms 53.79% 9.5MB 66.48%
// iterative dynamic programming
// O(N^2) O(N^2)
class Solution {
 public:
  int maxHeight(vector<vector<int>>& cuboids) {
    for (auto& cuboid : cuboids) {
      sort(cuboid.begin(), cuboid.end());
    }
    cuboids.push_back({0, 0, 0});
    sort(cuboids.begin(), cuboids.end());
    int n = cuboids.size(), ans = 0;
    vector<int> C(n);
    for (int j = 1; j < n; ++j) {
      for (int i = 0; i < j; ++i) {
        if (cuboids[i][0] <= cuboids[j][0] &&
            cuboids[i][1] <= cuboids[j][1] &&
            cuboids[i][2] <= cuboids[j][2]) {
          C[j] = max(C[j], C[i] + cuboids[j][2]);
          ans = max(ans, C[j]);
        }
      }
    }
    return ans;
  }
};
