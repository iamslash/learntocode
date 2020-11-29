/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// 0ms 100.00% 11.3MB 4.72%
// back tracking, recursive dynamic programming
// O(WB) O(WB)
class Solution {
 private:
  int dfs(vector<vector<int>>& W,
          vector<vector<int>>& B,
          vector<vector<int>>& C,
          int i, int usedBikes) {
    // base
    if (i >= W.size())
      return 0;
    // memo
    int& r = C[i][usedBikes];
    if (r >= 0)
      return r;
    // recursion
    r = INT_MAX;
    for (int j = 0; j < B.size(); ++j) {
      int nextBike = 1 << j;
      if (usedBikes & nextBike)
        continue;
      int dist = abs(W[i][0] - B[j][0]) +
          abs(W[i][1] - B[j][1]);
      r = min(r, dist + dfs(W, B, C, i+1, usedBikes | nextBike));
    }
    return r;
  }
 public:
  int assignBikes(vector<vector<int>>& W,
                  vector<vector<int>>& B) {
    vector<vector<int>> C(10, vector<int>(1024, -1));
    int usedBikes = 0;
    return dfs(W, B, C, 0, usedBikes);
  }
};
