/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

// 140ms 79.13% 21.7MB 7.66%
// recursive dynamic programming
// O(LF) O(LF)
#define MOD 1000000007
class Solution {
 private:
  int dfs(vector<vector<int>>& C, vector<int>& L,
          int finish, int u, int fuel) {
    // printf("u: %d, fuel: %d\n", u, fuel);
    // base
    if (fuel < 0)
      return 0;
    // memo
    int & r = C[u][fuel];
    if (r >= 0)
      return r;
    // recursion
    r = 0;
    if (u == finish)
      r++;
    for (int v = 0; v < L.size(); v++) {
      if (v == u)
        continue;
      int cost = abs(L[u] - L[v]);
      r = (r + dfs(C, L, finish, v, fuel-cost)) % MOD;
    }
    return r;
  }
 public:
  int countRoutes(vector<int>& L,
                  int start, int finish, int fuel) {
    vector<vector<int>> C(101, vector<int>(201, -1));
    return dfs(C, L, finish, start, fuel);
  }
};

