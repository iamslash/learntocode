/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// dynamic programming
// O(N) O(N)
class Solution {
 private:
  int dfs(vector<int>& C, vector<int>& A, int d, int i) {
    // printf("i: %d\n", i);
    int n = A.size();
    // base
    // if (i < 0 || i >= n)
    //   return 0;
    // memo
    int& r = C[i];
    if (r >= 0)
      return r;
    // recursion
    r = 1;
    for (int j = i-1; j >= max(0, i-d) && A[j] < A[i]; --j) {
      r = max(r, 1 + dfs(C, A, d, j));
    }
    for (int j = i+1; j <= min(i+d, n-1) && A[j] < A[i]; ++j) {
      r = max(r, 1 + dfs(C, A, d, j));
    }
    return r;
  }
 public:
  int maxJumps(vector<int>& A, int d) {
    int n = A.size();
    vector<int> C(n, -1);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, dfs(C, A, d, i));
    }
    return ans;
  }
};
