/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 0,30 5,10 15,20
// 0 5 10 15 20 30
// + +  -  +  -  -

// 9,10 4,9 4,17
// 4 4 9 9 10 17 
// + + - +  -  -

// 36ms 69.02% 12.7MB 52.19%
// sort
// O(NlgN) O(N)
class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    int dup = 0, ans = 0;
    vector<pair<int, int>> times;
    for (auto& intv : intervals) {
      times.emplace_back(intv[0], 1);
      times.emplace_back(intv[1], -1);
    }
    sort(times.begin(), times.end(), [](const pair<int, int>& a,
                                        const pair<int, int>& b) {
                                       if (a.first == b.first) {
                                         return a.second > b.second;
                                       }
                                       return a.first < b.first;
                                     });
    for (auto& pr : times) {
      dup += pr.second;
      ans = max(ans, dup);
    }
    return ans;
  }
};
