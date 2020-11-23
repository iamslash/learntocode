/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 1 2 2 2 3

// 16ms 100.00% 9.7MB 100.00%
// sort
// O(NlgN) O(1)
class Solution {
 public:
  double trimMean(vector<int>& A) {
    int n = A.size(), m = n * 0.9, p = n * 0.05;
    // printf("n: %d, m: %d, n: %d\n", n, m, p);
    sort(A.begin(), A.end());
    int sum = accumulate(A.begin() + p, A.begin() + p + m, 0);
    return (double)sum / m;
  }
};
