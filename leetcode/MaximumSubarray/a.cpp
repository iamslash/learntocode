/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// greedy algorithm
// O(N) O(1)
class Solution {
 public:
  int maxSubArray(vector<int>& A) {
    int cumMax = 0, glbMax = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
      cumMax = max(cumMax+A[i], A[i]);
      glbMax = std::max(cumMax, glbMax);
      cumMax = max(cumMax, 0);
    }
    return glbMax;        
  }
};

int main() {
  return 0;
}
