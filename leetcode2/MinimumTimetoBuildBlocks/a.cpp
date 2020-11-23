/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// 56ms 61.54% 9.8MB 48.08%
// priority queue
// O(NlgN) O(N)
class Solution {
 public:
  int minBuildTime(vector<int>& blocks, int split) {
    priority_queue<int> pq;
    for (int b : blocks)
      pq.push(-b);
    while (pq.size() > 1) {
      int a = -pq.top(); pq.pop();
      int b = -pq.top(); pq.pop();
      pq.push(-(b + split));
    }
    return -pq.top();
  }
};
