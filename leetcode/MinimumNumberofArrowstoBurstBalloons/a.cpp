/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//                         i
// [1,6], [2,8], [7,12], [10,16]   

// greedy
// sort by end pos in ascending order
// 84ms 44.19%
class Solution {
 public:
  int findMinArrowShots(std::vector<std::pair<int, int>>& V) {
    if (V.empty())
      return 0;
    std::sort(V.begin(), V.end(), [](const std::pair<int, int>& a,
                                     const std::pair<int, int>& b) {
                return a.second < b.second;
              });
    int cnt = 1;
    int pos = V[0].second;
    for (int i = 1; i < V.size(); ++i) {
      if (pos >= V[i].first)
        continue;
      cnt++;
      pos = V[i].second;
    }
    return cnt;
  }
};

int main() {

  std::vector<std::pair<int, int>> V = {
    {10, 16},
    {2, 8},
    {1, 6},
    {7, 12}};
  Solution sln;
  printf("%d\n", sln.findMinArrowShots(V));
  
  return 0;
}
