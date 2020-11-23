/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 56ms 98.44% 44.5MB 100.00%
// brute force
// O(WB) O(1)
class Solution {
 public:
  std::vector<int> assignBikes(std::vector<std::vector<int>>& W,
                               std::vector<std::vector<int>>& B) {
    std::vector<std::vector<std::pair<int, int>>> dist2pairs(2001);
    int m = W.size(), n = B.size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int dist = std::abs(W[i][0] - B[j][0]) +
            std::abs(W[i][1] - B[j][1]);
        dist2pairs[dist].push_back({i, j});
      }
    }
    std::vector<int> ans(m, -1);
    std::vector<bool> usedBike(n, false);
    for (int d = 0; d <= 2000; ++d) {
      for (int k = 0; k < dist2pairs[d].size(); ++k) {
        int freeWork = dist2pairs[d][k].first;
        int freeBike = dist2pairs[d][k].second;
        if (ans[freeWork] == -1 && !usedBike[freeBike]) {
          usedBike[freeBike] = true;
          ans[freeWork] = freeBike;
        }
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
