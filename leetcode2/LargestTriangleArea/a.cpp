/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// 52ms 23.98% 6.5MB 100.00%
// math
// O(N^3) O(1)
class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& P) {
    double ans = 0;
    for (auto &i : P) {
      for (auto &j : P) {
        for (auto &k : P) {
          ans = std::max(ans, 0.5 * abs(i[0] * j[1] + j[0] * k[1] +
                                        k[0] * i[1] - j[0] * i[1] -
                                        k[0] * j[1] - i[0] * k[1]));
        }
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
