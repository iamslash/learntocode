/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

// priority queue
// 1664ms 9.57% 117.4MB 6.67%
class Solution {
 public:
  vector<int> busiestServers(
      int k, vector<int>& arrival, vector<int>& load) {
    // {server id : job cnt}
    unordered_map<int, int> jobCntMap;
    // {job end time : server id} handled jobs
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    // {server id}
    set<int> availServerSet;
    int n = arrival.size();
    for (int i = 0; i < k && i < n; ++i) {
      pq.push({arrival[i] + load[i], i});
      jobCntMap[i]++;
    }
    for (int i = k; i < n; ++i) {
      if (availServerSet.size() ||
          (pq.size() && arrival[i] >= pq.top().first)) {
        while (pq.size() && arrival[i] >= pq.top().first) {
          availServerSet.insert(pq.top().second);
          pq.pop();
        }
        auto it = lower_bound(availServerSet.begin(),
                              availServerSet.end(),
                              i % k);
        if (it == availServerSet.end())
          it = availServerSet.begin();
        pq.push({arrival[i] + load[i], *it});
        jobCntMap[*it]++;
        availServerSet.erase(it);
      }
    }
    vector<int> ans;
    int maxJobCnt = INT_MIN;
    for (auto& pr : jobCntMap) {
      maxJobCnt = max(maxJobCnt, pr.second);
    }
    for (auto& pr: jobCntMap) {
      if (pr.second == maxJobCnt)
        ans.push_back(pr.first);
    }
    return ans;
  }
};
