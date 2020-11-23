/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

// 28ms 91.34% 8.6MB 64.58%
// recursive dynamic programming
// O((N*2^M)*M) O(N*2^M)
class Solution {
 private:
  int C[13][4096] = {};
  int dfs(vector<vector<int>>& cost, vector<int>& min2,
          int i, int bm) {
    int h = cost.size(), w = cost[0].size();    
    // memo
    int& r = C[i][bm];
    if (r > 0)
      return r - 1;
    // recursion
    int ans = 0;
    if (i >= h) {
      for (int j = 0; j < w; ++j) {
        ans += min2[j] * ((bm & (1 << j)) == 0);
      }
    } else {
      ans = INT_MAX;
      for (int j = 0; j < w; ++j) {
        ans = min(ans, cost[i][j] +
                  dfs(cost, min2, i+1, bm | (1 << j)));
      }
    }
    r = ans + 1;
    return ans;
  }
 public:
  int connectTwoGroups(vector<vector<int>>& cost) {
    int h = cost.size(), w = cost[0].size();
    vector<int> min2(w, INT_MAX);
    for (int j = 0; j < w; ++j) {
      for (int i = 0; i < h; ++i) {
        min2[j] = min(min2[j], cost[i][j]);
      }
    }
    printf("%d %d\n", min2[0], min2[1]);
    return dfs(cost, min2, 0, 0);
  }
};

// 40ms 69.02% 33.9MB 8.31%
// recursive dynamic programming
// O((N*2^M)*M) O(N*2^M)
class Solution {
 private:
  int dfs(vector<vector<int>>& cost, vector<int>& min2,
          vector<vector<int>>& C, int i, int bm) {
    int h = cost.size(), w = cost[0].size();    
    // memo
    int& r = C[i][bm];
    if (r >= 0)
      return r;
    // recursion
    r = 0;
    if (i >= h) {
      for (int j = 0; j < w; ++j) {
        r += min2[j] * ((bm & (1 << j)) == 0);
      }
    } else {
      r = INT_MAX;
      for (int j = 0; j < w; ++j) {
        r = min(r, cost[i][j] + dfs(cost, min2, C, i+1, bm | (1 << j)));
      }
    }
    return r;
  }
 public:
  int connectTwoGroups(vector<vector<int>>& cost) {
    int h = cost.size(), w = cost[0].size();
    vector<int> min2(w, INT_MAX);
    vector<vector<int>> C(13, vector<int>(4096, -1));
    for (int j = 0; j < w; ++j) {
      for (int i = 0; i < h; ++i) {
        min2[j] = min(min2[j], cost[i][j]);
      }
    }
    return dfs(cost, min2, C, 0, 0);
  }
};
