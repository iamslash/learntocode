/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>


// 104ms 41.89% 24.5MB 56.36%
// BFS with multi visits
// O(HWN) O(HW)
class Solution {
 public:
  int shortestDistance(std::vector<std::vector<int>>& G) {
    if (G.empty() || G[0].empty())
      return -1;
    int h = G.size();
    int w = G[0].size();
    std::vector<std::vector<int>> dist(h, std::vector<int>(w, 0));
    std::vector<std::vector<int>> arrv(h, std::vector<int>(w, 0));
    int nbld = 0; // count of buildings

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};    

    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] == 1) {
          nbld++;
          std::queue<std::pair<std::pair<int, int>, int>> q;
          q.push({{y, x}, 0});
          std::vector<std::vector<bool>> seen(h, std::vector<bool>(w, false));

          while (!q.empty()) {
            auto u = q.front(); q.pop();
            // printf("%2d %2d %2d %2d\n", u.m_y, u.m_x, u.m_pid, u.m_dist);     
            for (int i = 0; i < 4; ++i) {
              int vy = u.first.first  + dy[i];
              int vx = u.first.second + dx[i];
              if (vy < 0 || vy >= h || vx < 0 || vx >= w ||
                  G[vy][vx] != 0 || seen[vy][vx])
                continue;
              int vd = u.second + 1;
              dist[vy][vx] += vd;
              arrv[vy][vx] += 1;
              seen[vy][vx] = true;
              q.push({{vy, vx}, vd});
            }
          }          
        }
      }
    }
    //
    int mindist = INT_MAX;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] == 0 && arrv[y][x] == nbld)
          mindist = std::min(mindist, dist[y][x]);
      }
    }
    
    return mindist == INT_MAX ? -1 : mindist;
  }
};

int main() {

  // std::vector<std::vector<int>> G =
  //     {
  //       {1,0,2,0,1},
  //       {0,0,0,0,0},
  //       {0,0,1,0,0}
  //     };
  std::vector<std::vector<int>> G =
      {
        {1,1,1,1,1,0},
        {0,0,0,0,0,1},
        {0,1,1,0,0,1},
        {1,0,0,1,0,1},
        {1,0,1,0,0,1},
        {1,0,0,0,0,1},
        {0,1,1,1,1,0}
      };
  
  Solution sln;
  printf("%d\n", sln.shortestDistance(G));
  
  return 0;
}
