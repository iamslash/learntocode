/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdint>

using namespace std;

//       k: 2
//     eff: 5 4  3 9 7 2
//     spd: 2 10 3 1 5 8
//
//              i
// effSpds: 9 7 5  4 3 2
//          1 5 2 10 3 8
//
//      pq: 2 5
//  sumSpd: 7 
//     ans: 14

// 232ms 52.81% 37.1MB 44.39%
// priority queue
// O(NlgN) O(N)
#define MOD 1000000007
class Solution {
 public:
  int maxPerformance(int n, vector<int>& spd, vector<int>& eff, int k) {
    vector<pair<int, int>> effSpds;
    for (int i = 0; i < n; ++i) {
      effSpds.emplace_back(eff[i], spd[i]);
    }
    sort(effSpds.rbegin(), effSpds.rend());
    int64_t sumSpd = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& pr : effSpds) {
      int uEff = pr.first, uSpd = pr.second;
      pq.emplace(uSpd);
      sumSpd += uSpd;
      if (pq.size() > k) {
        sumSpd -= pq.top(); pq.pop();
      }
      ans = max(ans, sumSpd * uEff);
    }
    return ans % MOD;
  }
};
