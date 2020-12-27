/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// C[n] = C[0] * C[n-1] +
//        C[1] * C[n-2] +
//        C[2] * C[n-3] +
//        ...
//        C[n-1] * C[0]

// 0ms 100.00% 6.3MB 42.98%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int numTrees(int n) {
    vector<int> C(n+1);
    C[0] = C[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        C[i] += C[j-1] * C[i-j];
      }
    }
    return C[n];    
  }
};

// 0ms 100.00% 6.4MB 42.98%
// recursive dynamic programming
// O(N) O(N)
class Solution {
 private:
  int dfs(vector<int>& C, int n) {
    // base
    if (n <= 1)
      return 1;
    // memo
    int& r = C[n];
    if (r >= 0)
      return r;
    // recursion
    r = 0;
    for (int i = 0; i < n; ++i) {
      r += dfs(C, i) * dfs(C, n-1-i);
    }
    return r;
  }
 public:
  int numTrees(int n) {
    vector<int> C(n+1, -1);
    return dfs(C, n);
  }
};
