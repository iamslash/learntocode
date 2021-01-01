/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// apples: 1 2 3 5 2
//   days: 3 2 1 4 2

// 676ms 40.97% 47.5MB 4
// priority_queue
// O(NlgN) O(N)
class Solution {
 public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    int ans = 0, n = apples.size();
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    int i = 0;
    while (i < n || pq.size()) {
      // Add today's apple
      if (i < n && apples[i] > 0) {
        pq.push({i + days[i] - 1, apples[i]});
      }
      // Remove apples
      while (pq.size() && pq.top().first < i) {
        pq.pop();
      }
      // Eat
      if (pq.size()) {
        auto pr = pq.top(); pq.pop();
        if (pr.second > 1) {
          pq.push({pr.first, pr.second-1});
        }
        ++ans;
      }
      ++i;
    }
    return ans;
  }
};
