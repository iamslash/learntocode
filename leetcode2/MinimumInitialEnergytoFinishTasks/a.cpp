/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 1016ms 45.70% 93.6MB 86.40%
// greedy, sort
// O(N) O(1)
class Solution {
 public:
  int minimumEffort(vector<vector<int>>& tasks) {
    int ans = 0, n = tasks.size();
    for (int i = 0; i < n; ++i) {
      tasks[i][0] = tasks[i][1] - tasks[i][0];
    }
    sort(tasks.begin(), tasks.end());
    for (int i = 0; i < n; ++i) {
      ans = max(ans + tasks[i][1] - tasks[i][0], tasks[i][1]);
    }
    return ans;
  }
};
