/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

// 0ms 100.00% 8.9MB 83.33%
// back tracking
// O(?) O(?)
class Solution {
 private:
  void dfs(vector<int>& toppingCosts,
           int target, int& best, int cost, int i) {
    // base
    if (cost >= target || i >= toppingCosts.size()) {
      if (abs(cost - target) < abs(best - target)) {
        best = cost;
      } else if (abs(cost - target == abs(best - target))) {
        best = min(best, cost);
      }
      return;
    }
    // recursion
    for (int j = 0; j <= 2; ++j) {
      dfs(toppingCosts, target, best,
          cost + j * toppingCosts[i], i+1);
    }
  }
 public:
  int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
    int best = INT_MAX;
    for (int base : baseCosts) {
      dfs(toppingCosts, target, best, best, 0);
    }
    return best;
  }
};
