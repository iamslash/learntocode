/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// 136ms 94.36% 22.8MB 77.94%
// greedy, priority queue
// O(PlgP) O(P)
class Solution {
 public:
  int findMaximizedCapital(int k, int W,
                           vector<int>& P, vector<int>& C) {
    priority_queue<int> low; // doable projects
    multiset<pair<int, int>> high; // undoable projects

    for (int i = 0; i < P.size(); ++i) {
      if (P[i] > 0) {
        if (C[i] <= W) {
          low.push(P[i]);
        } else {
          high.insert({C[i], P[i]});
        }        
      }
    }
    while (k-- > 0 && low.size()) {
      W += low.top(); low.pop();
      for (auto it = high.begin();
           high.size() && it->first <= W;
           it = high.erase(it)) {
        low.push(it->second);
      }
    }
    return W;
  }
};
