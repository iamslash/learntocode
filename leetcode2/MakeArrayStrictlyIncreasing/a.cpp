/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

//      i
// A: 1 5 3 6 7
// 
// B: 1 2 3 4


//        i
// A: 1 3 3 6 7
// 
// B: 1 3 4

// recursive dynamic porgramming
// 348ms 52.81% 26.8MB 63.20%
class Solution {
 private:
  int C[2001][2001] = {};
  int val = 2002;
  int dfs(vector<int>&A, vector<int>& B, int i, int j, int prev) {
    // base
    if (i >= A.size())
      return 1;
    j = upper_bound(B.begin() + j, B.end(), prev) - B.begin();
    if (prev >= A[i] && j >= B.size())
      return val;
    // memo
    int& r = C[i][j];
    if (r > 0)
      return r;
    // recursion
    r = val;
    if (j < B.size()) {
      r = 1 + dfs(A, B, i+1, j, B[j]);      
    }
    if (prev < A[i]) {
      r = min(r, dfs(A, B, i + 1, j, A[i]));
    }
    return r;
  }
 public:
  int makeArrayIncreasing(vector<int>& A, vector<int>& B) {
    sort(B.begin(), B.end());
    auto ans = dfs(A, B, 0, 0, INT_MIN);
    return ans >= val ? -1 : ans - 1;
  }
};
