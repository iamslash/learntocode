/* Copyright (C) 2020 by iamslash */

#include <vector>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <numeric>

using namespace std;

// 1 1 1
// 1 3 1
// 1 3 5
// 9 3 5

// 84ms 98.56%
// priority queue
// O(NlgN) O(1)
class Solution {
 public:
  bool isPossible(vector<int>& target) {
    int64_ sum = accumulate(begin(target), end(target), (int64_t)0);
    priority_queue<int> pq(begin(target), end(target));
    while (sum > 1 && pq.top() > sum/2) {
      int64_t top = pq.top(); pq.pop();
      sum -= top;
      if (sum <= 1)
        return sum;
      int64_t num = top % sum;
      pq.push(num);
      sum += num;
    }
    return sum == target.size();
  }
};
