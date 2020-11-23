/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

// 540ms 20.52% 410.6MB 5.06%
#define MOD 1000000007
class Solution {
 private:
  vector<vector<int>> C;
  int comb(int a, int b) {
    // base
    if (a == 0 || b == 0)
      return 1;
    // memo
    int& r = C[a][b];
    if (r > 0)
      return r;
    // recursion
    r = (comb(a-1, b) + comb(a, b-1)) % MOD;
    return r;
  }
  int64_t dfs(vector<int>& A) {
    if (A.size() <= 1)
      return 1;
    vector<int> left, right;
    copy_if(A.begin(), A.end(), back_inserter(left), [&](int a){ return a < A.front(); });
    copy_if(A.begin(), A.end(), back_inserter(right), [&](int a){ return a > A.front(); });
    return comb(left.size(), right.size()) % MOD * dfs(left) * dfs(right) % MOD;
  }
 public:
  int numOfWays(vector<int>& A) {
    int n = A.size();
    C = vector<vector<int>>(1001, vector<int>(1001, 0));
    return dfs(A) - 1;
  }
};
