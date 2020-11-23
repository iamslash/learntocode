/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 12ms 69.08% 8.6MB 5.54%
// recursive dynamic programming
// O(KN^2) O(KN^2)
class Solution {
 private:
  double dfs(vector<vector<vector<double>>>& C,
             int n, int k, int y, int x) {
    // base
    if (k == 0) {
      return 1;
    }
    // memo
    double& r = C[k][y][x];
    if (r > 0)
      return r;      

    // recursion
    r = 0.0;
    int dy[8] = {-2, -1, 1, 2, 2,  1, -1, -2};
    int dx[8] = { 1,  2, 2, 1, -1,-2, -2, -1};
    for (int i = 0; i < 8; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n)
        continue;
      r += dfs(C, n, k-1, ny, nx);
    }
    r /= 8.0;
    return r;
  }
 public:
  double knightProbability(int N, int K, int r, int c) {
    vector<vector<vector<double>>> C(
        K+1, vector<vector<double>>(
            N, vector<double>(N, -1.0)));
    return dfs(C, N, K, r, c);                                                        
  }
};
