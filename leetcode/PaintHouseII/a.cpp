/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

// 24ms 22.87% 10.2MB 65.79%
// O(NK) O(1)
class Solution {
 public:
  int minCostII(std::vector<std::vector<int>>& costs) {
    if (costs.size() == 0)
      return 0;
    int h = costs.size();
    int w = costs[0].size();

    int prvmin1 = 0;  // previous 1st min cost
    int prvmin2 = 0;  // previous 2nd min cost
    int prvidx1 =-1;  // previous index of 1st min cost

    for (int i = 0; i < h; ++i) {
      int curmin1 = INT_MAX;  // current 1st min cost
      int curmin2 = INT_MAX;  // current 2nd min cost
      int curidx1 = -1;       // current index of 1st min cost

      for (int j = 0; j < w; ++j) {
        int cost = costs[i][j] + (j != prvidx1 ? prvmin1 : prvmin2);
        if (cost < curmin1) {
          curmin2 = curmin1;
          curmin1 = cost;
          curidx1 = j;
        } else if (cost < curmin2) {
          curmin2 = cost;
        }
      }
      prvmin1 = curmin1;
      prvmin2 = curmin2;
      prvidx1 = curidx1;
    }
    return prvmin1;
  }
};

int main() {

  std::vector<std::vector<int>> costs = {{1, 5, 3}, {2, 9, 4}};
  Solution sln;
  printf("%d\n", sln.minCostII(costs));
  
  return 0;
}
