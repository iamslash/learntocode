/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// 0 0
// 0 1
//
// 0 1
// 1 1

// 64ms 21.02% 10.9MB 100.00
// BFS
// O(N!) O(N)
class Solution {
 private:
  vector<vector<int>> flipMatrix(vector<vector<int>> M, int y, int x) {
    int h = M.size(), w = M[0].size();
    int ds[5] = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int ny = y + ds[i];
      int nx = x + ds[i+1];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w)
        continue;
      M[ny][nx] ^= 1;
    }
    M[y][x] ^= 1;
    return M;
  }
  bool zeroMatrix(const vector<vector<int>>& M) {
    int h = M.size(), w = M[0].size();
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (M[y][x] != 0)
          return false;
      }
    }
    return true;
  }
  
 public:
  int minFlips(vector<vector<int>>& M) {
    if (zeroMatrix(M))
      return 0;
    int h = M.size(), w = M[0].size(), step = 0;
    set<vector<vector<int>>> seen;
    seen.insert(M);
    queue<vector<vector<int>>> q;
    q.push(M);
    while (q.size() > 0) {
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        auto u = q.front(); q.pop();
        // end codntion
        if (zeroMatrix(u))
          return step;
        for (int y = 0; y < h; ++y) {
          for (int x = 0; x < w; ++x) {
            auto v = flipMatrix(u, y, x);
            if (seen.insert(v).second) {
              q.push(v);
            }
          }
        }
      }
      step++;      
    }
    return -1;
  }
};

