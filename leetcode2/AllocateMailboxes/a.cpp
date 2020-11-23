/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 136ms 24.92% 8.7MB 83.33%
// dynamic programming
// O(NK) O(NK)
#define MAXDIST 1000000
class Solution {
 private:  
  int dfs(vector<vector<int>>& C, vector<int>& H, int k, int u) {
    // base
    int n = H.size();
    if (u >= n) {
      if (k == 0) {
        return 0;
      }
      return MAXDIST;
    }
    if (k == 0)
      return MAXDIST;
    // memo
    int& r = C[u][k];
    if (r >= 0)
      return r;    
    // recursion
    r = MAXDIST;
    for (int v = u; v < n; ++v) {
      int m = (u+v)/2;
      int dist = 0;
      for (int i = u; i <= v; ++i) {
        dist += abs(H[m] - H[i]);
      }
      r = min(r, dist + dfs(C, H, k-1, v+1));
    }
    return r;
  }
 public:
  int minDistance(vector<int>& H, int k) {
    int n = H.size();
    sort(H.begin(), H.end());
    vector<vector<int>> C(n, vector<int>(k+1, -1));
    return dfs(C, H, k, 0);
  }
};
