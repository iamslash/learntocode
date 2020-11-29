/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// 8ms 100.00% 8MB 50.00%
// brute force
// O(CA) O(1)
class Solution {
 public:
  int maximumWealth(vector<vector<int>>& customers) {
    int ans = 0;
    for (auto& accounts : customers) {
      ans = max(ans, accumulate(accounts.begin(), accounts.end(), 0));
    }
    return ans;
  }
};
