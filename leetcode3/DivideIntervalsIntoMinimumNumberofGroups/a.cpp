/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

// intervals: 5,10 6,8 1,5 2,3 1,10
//                                                     i
//      evts: 1,1 1,1 2,1 4,- 6,- 5,1, 6,1 9,- 11,- 11,-
//       cur    0
//       ans:   3

// 609ms 10.46% 146.1MB 19.77%
// sort
// O(NlgN) O(N)
class Solution {
public:
  int minGroups(vector<vector<int>>& intervals) {
    vector<vector<int>> evts;
    for (auto& interval : intervals) {
      evts.push_back({interval[0], 1});
      evts.push_back({interval[1] + 1, -1});
    }
    int ans = 0, cur = 0;
    sort(evts.begin(), evts.end());
    for (auto& evt : evts) {
      ans = max(ans, cur += evt[1]);
    }
    return ans;
  }
};
