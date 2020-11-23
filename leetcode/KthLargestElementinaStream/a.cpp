/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <queue>
#include <vector>

// 44ms 93.85% 18.7MB 100.00%
// priority queue
// O(lgN) O(N)
class KthLargest {
 private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  int limit;
 public:
  KthLargest(int k, std::vector<int>& nums) {
    limit = k;
    int i;
    for (i = 0; i < k && i < nums.size(); ++i) {
      pq.push(nums[i]);
    }
    for (; i < nums.size(); ++i) {
      add(nums[i]);
    }
  }    
  int add(int val) {
    if (pq.size() < limit) {
      pq.push(val);
    } else if (pq.top() < val) {
      pq.pop();
      pq.push(val);
    }
    return pq.top();
  }
};


int main() {
  return 0;
}
