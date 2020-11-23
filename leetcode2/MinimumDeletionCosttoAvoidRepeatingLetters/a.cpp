/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

//                  i
//       s: a b a a c
//    cost: 1 2 3 4 5
// maxCost: 1 2 3 4 5
//     ans: 0 0 0 3 3

// 484ms 39.27% 95.8MB 29.81%
// linear traversal
// O(N) O(1)
class Solution {
 public:
  int minCost(string s, vector<int>& cost) {
    int ans = 0, maxCost = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
      if (i > 0 && s[i] != s[i-1]) {
        maxCost = 0;
      }
      ans += min(maxCost, cost[i]);
      maxCost = max(maxCost, cost[i]);
    }
    return ans;
  }
};
