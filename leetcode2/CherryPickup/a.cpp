/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

//  1  1 -1
//  1 -1  1
// -1  1  1

// 64ms 69.78% 22.27MB 31.82%
// dynamic programming
// O(N^3) O(N^3)
class Solution {
 private:
  int dfs(vector<vector<vector<int>>>& C,
          vector<vector<int>>& G,
          int y1, int x1, int x2) {
    // base
    int n = G.size();
    int y2 = y1 + x1 - x2;
    if (y1 >= n || y2 >= n || x1 >= n || x2 >= n ||
        G[y1][x1] < 0 || G[y2][x2] < 0)
      return INT_MIN;
    if (y1 == n - 1 && x1 == n - 1 && x2 == n - 1)
      return G[n-1][n-1];
    // memo
    int& r = C[y1][x1][x2];
    if (r > INT_MIN)
      return r;
    // recursion
    r = max(max(dfs(C, G, y1+1, x1, x2),
                dfs(C, G, y1, x1+1, x2+1)),
            max(dfs(C, G, y1+1, x1, x2+1),
                dfs(C, G, y1, x1+1, x2)));
    if (r < 0)
      return r = -1;
    r += G[y1][x1];
    if (y1 != y2)
      r += G[y2][x2];
    return r;
  }
 public:
  int cherryPickup(vector<vector<int>>& G) {
    int n = G.size();
    vector<vector<vector<int>>> C(
        n, vector<vector<int>>(
            n, vector<int>(
                n, INT_MIN)));
    return max(0, dfs(C, G, 0, 0, 0));    
  }
};

// 68ms 66.07% 22.5MB 41.89%
// dynamic programming
// O(N^3) O(N^3)
class Solution {
 private:
  int dfs(vector<vector<vector<int>>>& C,
          vector<vector<int>>& G,
          int y1, int x1, int x2) {
    // base
    int n = G.size();
    int y2 = y1 + x1 - x2;
    if (y1 < 0 || y2 < 0 || x1 < 0 || x2 < 0 ||
        G[y1][x1] < 0 || G[y2][x2] < 0)
      return -1;
    if (y1 == 0 && x1 == 0 && x2 == 0)
      return G[0][0];
    // memo
    int& r = C[y1][x1][x2];
    if (r > INT_MIN)
      return r;
    // recursion
    r = max(max(dfs(C, G, y1-1, x1, x2),
                dfs(C, G, y1, x1-1, x2-1)),
            max(dfs(C, G, y1-1, x1, x2-1),
                dfs(C, G, y1, x1-1, x2)));
    if (r < 0)
      return r = -1;
    r += G[y1][x1];
    if (y1 != y2)
      r += G[y2][x2];    
    return r;
  }
 public:
  int cherryPickup(vector<vector<int>>& G) {
    int n = G.size();
    vector<vector<vector<int>>> C(
        n, vector<vector<int>>(
            n, vector<int>(
                n, INT_MIN)));
    return max(0, dfs(C, G, n-1, n-1, n-1));    
  }
};
