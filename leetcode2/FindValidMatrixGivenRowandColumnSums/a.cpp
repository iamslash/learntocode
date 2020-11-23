/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 96ms 82.79% 33.6MB 5.53%
// greedy algorithm
// O(HW) O(HW)
class Solution {
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int h = rowSum.size(), w = colSum.size();
    vector<vector<int>> ans(h, vector<int>(w));
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        int v = min(rowSum[y], colSum[x]);
        rowSum[y] -= v;
        colSum[x] -= v;
        ans[y][x] = v;
      }
    }
    return ans;
  }
};
