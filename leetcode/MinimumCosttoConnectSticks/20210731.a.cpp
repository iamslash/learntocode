/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 136ms 19.10% 12.5MB 100.00%
// greedy approach
// O(NlgN) O(N)
class Solution {
 public:
  int connectSticks(std::vector<int>& S) {
    std::priority_queue<int> pq;
    for (int a : S)
      pq.push(-a);
    int ans = 0;
    while (pq.size() > 1) {
      int a = -pq.top(); pq.pop();
      int b = -pq.top(); pq.pop();
      int c = a + b;
      pq.push(-c);
      ans += c;   
    }
    return ans;
  }
};

int main() {
  return 0;
}
