/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// It is so difficult to understand.
// 348ms 46.02% 378.2MB 5.11%
class Solution {
 private:
  int dfs(vector<vector<vector<int>>>& C, vector<int>& B,
          int lo, int hi, int k) {
    // base
    if (lo == hi)
      return (k+1)*(k+1);
    if (lo > hi)
      return 0;
    // memo
    int& r = C[lo][hi][k];
    if (r >= 0)
      return r;
    // recursion
    while (lo + 1 <= hi && B[lo] == B[lo+1]) {
      lo++;
      k++;
    }
    r = dfs(C, B, lo+1, hi, 0) + (k+1)*(k+1);
    for (int i = lo+1; i <= hi; ++i) {
      if (B[i] == B[lo]) {
        r = max(r, dfs(C, B, lo+1, i-1, 0) + dfs(C, B, i, hi, k+1));
      }
    }
    return r;
  }
 public:
  int removeBoxes(vector<int>& B) {
    vector<vector<vector<int>>> C(
        100, vector<vector<int>>(
            100, vector<int>(100, -1)));
    return dfs(C, B, 0, B.size()-1, 0);
  }
};
