/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//   A: 1 2 3 4 5 6 7 8
// sum: 36
//   n: 8

// 0ms 100.00% 8.2MB 94.10%
// math
class Solution {
 private:  
  bool dfs(vector<int>& A, int len, int sum, int beg) {
    // base
    int n = A.size();
    if (len == 0)
      return sum == 0;
    if (A[beg] > sum / len)
      return false;
    for (int i = beg; i < n - len + 1; i++) {
      if ( i > beg && A[i] == A[i-1])
        continue;
      if (dfs(A, len - 1, sum - A[i], i + 1))
        return true;
    }
    return false;
  }
 public:
  bool splitArraySameAverage(vector<int>& A) {
    int n = A.size(), sum = 0;
    for (int a : A)
      sum += a;
    sort(A.begin(), A.end());
    for (int len = 1; len <= n/2; ++len) {
      if (sum * len % n > 0)
        continue;
      if (dfs(A, len, len * sum / n, 0))
        return true;
    }
    return false;
  }
};
