/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// 12ms 100.00%
// line sweeping
// O(N^2) O(N)
class Solution {
 public:
  int rectangleArea(std::vector<std::vector<int>>& R) {
    int mod = 10e8+7;
    // {x, {y, degree}}
    std::map<int, std::vector<std::pair<int, int>>> smp_xydeg;
    for (auto& r : R) {
      smp_xydeg[r[0]].push_back({r[1], 1});
      smp_xydeg[r[0]].push_back({r[3], -1});
      smp_xydeg[r[2]].push_back({r[1], -1});
      smp_xydeg[r[2]].push_back({r[3], 1});
    }
    int64_t area = 0, prv_x = 0, dy = 0;
    std::map<int, int> smp_yref; // {y, reference count}
    for (auto& xg : smp_xydeg) {
      area += (xg.first - prv_x) * dy % mod;
      printf("(%d, %d) : %d\n", xg.first, xg.second[0].first, area);
      for (auto& ydeg : xg.second)
        smp_yref[ydeg.first] += ydeg.second;
      dy = 0;
      int start = 0, cnt = 0;
      for (auto& ref : smp_yref) {
        if (cnt == 0)
          start = ref.first;
        cnt += ref.second;
        if (cnt == 0)
          dy += ref.first - start;
      }
      prv_x = xg.first;
    }
    return area % mod;
  }
};

int main() {
  // std::vector<std::vector<int>> R = {{0,0,2,2},{1,0,2,3},{1,0,3,1}};
  // std::vector<std::vector<int>> R = {{0,0,1000000000,1000000000}};
  std::vector<std::vector<int>> R = {{0,0,2,2},{1,1,3,3},{2,2,4,4}};
  Solution sln;
  printf("%d\n", sln.rectangleArea(R));
  return 0;
}
