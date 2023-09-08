/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <queue>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;


// Idea: bfs, dijkstra
//
// grid:
// 0 0 0 1
// 0 0 0 0
// 0 0 0 0
// 1 0 0 0
//
// grid: After bfs
// 4 3 2 1
// 3 4 3 2
// 2 3 4 3
// 1 2 3 4

// 431ms 8805% 110MB 92.48%
// bfs, dijkstra
// O(NlgN) O(N)
// N: number of cells
class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    // Update cost in grid
    queue<array<int, 2>> q;
    int dir[5] = {1, 0, -1, 0, 1};
    int n = grid.size();
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        if (grid[y][x] > 0) {
          q.push({y, x});
        }
      }
    }
    while (!q.empty()) {
      auto [i, j] = q.front(); q.pop();
      for (int d = 0; d < 4; ++d) {
        int y = i + dir[d], x = j + dir[d + 1];
        if (y >= 0 && y < n && x >= 0 && x < n && grid[y][x] == 0) {
          grid[y][x] = grid[i][j] + 1;
          q.push({y, x});
        }
      }
    }
    // dijkstra
    priority_queue<array<int, 3>> pq;
    pq.push({grid[0][0], 0, 0});
    while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
      auto [c, i, j] = pq.top(); pq.pop();
      for (int d = 0; d < 4; ++d) {
        int y = i + dir[d], x = j + dir[d + 1];
        if (y >= 0 && y < n && x >= 0 && x < n && grid[y][x] > 0) {
          pq.push({min(c, grid[y][x]), y, x});
          grid[y][x] *= -1;
        }
      }
    }
    return pq.top()[0] - 1;
  }
};

int main() {
  return 0;
}

