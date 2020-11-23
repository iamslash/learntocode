/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <deque>
#include <vector>
#include <unordered_set>

using namespace std;

// 312ms 25.42% 22.2MB 23.59%
// BFS, deque
// O(HW) O(HW)
class Solution {
 public:
  int minCost(vector<vector<int>>& G) {
    int h = G.size(), w = G[0].size();
    deque<pair<int, int>> q{{0, 0}};  // {mixed-pos, cost}
    int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    unordered_set<int> seen;
    int ans = 0;
    // BFS loop
    while (q.size()) {
      auto u = q.front(); q.pop_front();
      int y = u.first / w, x = u.first % w;
      if (seen.insert(u.first).second)
        ans = u.second;
      if (y == h-1 && x == w-1)
        return ans;
      for (auto dir : dirs) {
        int ny = y + dir[0];
        int nx = x + dir[1];
        int pos = ny * w + nx;
        if (ny < 0 || ny >= h || nx < 0 || nx >= w || seen.count(pos) > 0)
          continue;
        int cost = 1;
        if ((G[y][x] == 1 && dir[0] ==  0 && dir[1] ==   1) ||
            (G[y][x] == 2 && dir[0] ==  0 && dir[1] ==  -1) ||
            (G[y][x] == 3 && dir[0] ==  1 && dir[1] ==   0) ||
            (G[y][x] == 4 && dir[0] == -1 && dir[1] ==   0))
          cost = 0;
        if (cost == 1)
          q.push_back({pos, u.second + cost});
        else
          q.push_front({pos, u.second + cost});
      }
    }
    return ans;
  }
};
