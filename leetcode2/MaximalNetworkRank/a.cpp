/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

// 0: 1 3
// 1: 0 2 3
// 2: 1
// 3: 0 1
//
// 0: 2
// 1: 3
// 2: 1
// 

// 200ms 62.59% 39.3MB 5.13%
// hash set
// O(N^2) O(N^2)
class Solution {
 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    int ans = 0;
    vector<unordered_set<int>> G(n);
    vector<int> cnts(n);
    for (auto& road : roads) {
      int u = road[0], v = road[1];
      G[u].insert(v); G[v].insert(u);
      cnts[u]++; cnts[v]++;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        ans = max(ans, cnts[i] + cnts[j] - (int)G[i].count(j)); 
      }
    }
    return ans;
  }
};
