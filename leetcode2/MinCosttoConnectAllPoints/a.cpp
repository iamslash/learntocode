/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

// 460ms 75.11% 58.3MB 41.10%
// kruskal algorithm
class Solution {
 private:
  int find(vector<int>& ds, int i) {
    if (ds[i] < 0)
      return i;
    return ds[i] = find(ds, ds[i]);
  }
 public:
  int minCostConnectPoints(vector<vector<int>>& P) {
    int n = P.size(), ans = 0;
    vector<int> ds(n, -1);
    vector<array<int, 3>> arr;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int dist = abs(P[i][0] - P[j][0]) + abs(P[i][1] - P[j][1]);
        arr.push_back({dist, i, j});
      }
    }
    make_heap(arr.begin(), arr.end(), greater<array<int, 3>>());
    while (arr.empty() == false) {
      pop_heap(arr.begin(), arr.end(), greater<array<int, 3>>());
      auto least = arr.back(); arr.pop_back();
      int dist = least[0], i = find(ds, least[1]), j = find(ds, least[2]);
      if (i != j) {
        ans += dist;
        ds[i] += ds[j];
        ds[j] = i;
        if (ds[i] == -n)
          break;
      }
    }
    return ans;
  }
};
