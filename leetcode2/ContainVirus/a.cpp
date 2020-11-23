/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

// 20ms 95.04% 18.6MB 46.81%
// DFS
// O(HW) O(HW)
#define MAX_VAL 1e9
class Solution {
 private:
  vector<vector<int>> G;
  unordered_set<int>  candSet;
  int h, w, c;
  // return total number of walls
  // wihch block this connected component
  int dfs(int y, int x) {
    // base
    if (y < 0 || y >= h || x < 0 || x >= w || G[y][x] != 1)
      return 0;
    int cnt = 0;
    if (y+1 < h && G[y+1][x] == 0) {
      candSet.insert((y+1) * w + x);
      cnt++;
    }
    if (y-1 >= 0 && G[y-1][x] == 0) {
      candSet.insert((y-1) * w + x);
      cnt++;
    }
    if (x+1 < w && G[y][x+1] == 0) {
      candSet.insert(y * w + (x + 1));
      cnt++;
    }
    if (x-1 >= 0 && G[y][x-1] == 0) {
      candSet.insert(y * w + (x - 1));
      cnt++;
    }
    G[y][x] = c;
    cnt += dfs(y+1, x);
    cnt += dfs(y-1, x);
    cnt += dfs(y, x+1);
    cnt += dfs(y, x-1);
    return cnt;
  }
 public:
  int containVirus(vector<vector<int>>& grid) {
    G = grid, h = grid.size(), w = grid[0].size();
    int ans = 0, maxCandidate = 0, maxWall = 0, maxCell = 0;
    while (true) {
      c = 2, maxCandidate = 0;
      for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
          if (G[y][x] == 1) {
            candSet.clear();
            int wall = dfs(y, x);
            if (maxCandidate < candSet.size()) {
              maxCandidate = candSet.size();
              maxWall = wall;
              maxCell = c;
            }
            c++;
          }
        }
      }
      if (maxCandidate == 0)
        break;
      ans += maxWall;
      // Install cells
      // Reset cells which are not installed
      for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
          if (G[y][x] == maxCell) {
            G[y][x] = MAX_VAL;
          } else if (G[y][x] > 1 && G[y][x] != MAX_VAL) {
            G[y][x] = 1;
            if (y+1 < h && G[y+1][x] == 0)
              G[y+1][x] = 1;
            if (y-1 >= 0 && G[y-1][x] == 0)
              G[y-1][x] = 1;
            if (x+1 < w && G[y][x+1] == 0)
              G[y][x+1] = 1;
            if (x-1 >= 0 && G[y][x-1] == 0)
              G[y][x-1] = 1;
          }
        }
      }
    }
    return ans;
  }
};
