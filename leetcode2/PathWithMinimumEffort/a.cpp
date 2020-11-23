/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// 700ms 31.82% 22.5MB 18.18%
// dijkstra
// O(ElgV) O(HW)
#define MAX_VAL 1000000
class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& H) {
    int dir[5] = {-1, 0, 1, 0, -1};
    int h = H.size(), w = H[0].size();
    vector<vector<int>> C(h, vector<int>(w, MAX_VAL));
    // [height, mixed y, x]
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);
    while (pq.size()) {
      auto pr = pq.top(); pq.pop();
      int cost = pr.first;
      int y = pr.second / 100, x = pr.second % 100;
      if (y == h - 1 && x == w - 1)
        return cost;
      if (cost >= C[y][x])
        continue;
      C[y][x] = cost;
      for (int i = 0; i < 4; ++i) {
        int ny = y + dir[i], nx = x + dir[i+1];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w)
          continue;
        int ncost = max(cost, abs(H[ny][nx] - H[y][x]));
        pq.emplace(ncost, ny * 100 + nx);
      }
    }
    return -1;
  }
};

