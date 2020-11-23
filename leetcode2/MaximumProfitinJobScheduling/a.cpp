/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

// 456ms 48.20% 73.2MB 18.19%
// hash map
// O(NlgN) O(N)
class Solution {
 public:
  int jobScheduling(vector<int>& S, vector<int>& E, vector<int>& P) {
    map<int, int> maxProfitMap = {{0, 0}};
    unordered_map<int, vector<pair<int, int>>> jobMap;
    int n = S.size();
    for (int i = 0; i < n; ++i) {
      maxProfitMap[S[i]] = 0;
      jobMap[S[i]].push_back({E[i], P[i]});
    }
    int maxProfit = 0;
    for (auto it = maxProfitMap.rbegin(); it != maxProfitMap.rend(); ++it) {
      for (auto pr : jobMap[it->first]) {
        int backProfit = 0;
        auto jt = maxProfitMap.lower_bound(pr.first);
        if (jt != maxProfitMap.end())
          backProfit = jt->second;
        maxProfit = max(maxProfit, pr.second + backProfit);
      }
      it->second = maxProfit;
    }
    return maxProfit;
  }
};
