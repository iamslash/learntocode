/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// _____
// 1 2 3 7

// 536ms 52.82% 146.4MB 28.77%
// dynamic programming
// O(N) O(N)
class Solution {
 private:
  int dfs(vector<int>& C, vector<int>& S, int i) {
    printf("i:%d\n", i);
    // base
    int n = S.size();
    if (i >= n)
      return 0;
    // memo
    int& r = C[i];
    if (r != INT_MIN)
      return r;
    // recursion
    r = INT_MIN;
    for (int j = 0, sum = 0; j < 3 && i + j < n; ++j) {
      sum += S[i+j];
      r = max(r, sum - dfs(C, S, i+j+1));
    }
    return r;
  }
 public:
  string stoneGameIII(vector<int>& S) {
    vector<int> C(S.size(), INT_MIN);
    int r = dfs(C, S, 0);
    
    if (r > 0)
      return "Alice";
    else if (r < 0)
      return "Bob";
    return "Tie";
  }
};
