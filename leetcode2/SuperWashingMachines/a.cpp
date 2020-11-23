/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

// 12ms 100.00% 13.3MB 31.36%
// linear traversal
// O(N) O(1)
class Solution {
 public:
  int findMinMoves(vector<int>& M) {
    int n = M.size();
    int total = accumulate(M.begin(), M.end(), 0);
    if (total % n != 0)
      return -1;
    int avg = total / n;
    int ans = 0, sum = 0;
    for (int m : M) {
      sum += m - avg;
      ans = max(ans, max(abs(sum), m - avg));
    }
    return ans;
  }
};
