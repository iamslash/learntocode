/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>


using namespace std;

// i       j
// 1 2 3 4 5 6 1

// 156ms 27.22% 42.6MB 58.39%
// linear traversal
// O(N) O(1)
class Solution {
 public:
  int maxScore(vector<int>& P, int k) {
    int n = P.size(), i = 0, j = n - k;
    int sum = accumulate(P.begin()+j, P.end(), 0);
    int ans = sum;
    while (k-- > 0) {
      sum += P[i++] - P[j++];
      ans = max(ans, sum);
    }
    return ans;
  }
};
