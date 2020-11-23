/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>

// 40ms 77.37% 13.7MB 85.90%
// BFS
// O(HW) O(N)
class Solution {
 public:
  int shortestDistance(std::vector<std::vector<int>>& G,
                       std::vector<int>& S, std::vector<int>& D) {
    if (G.empty() || G[0].empty())
      return -1;
    int h = G.size();
    int w = G[0].size();
    int dlt[5] = {-1, 0, 1, 0, -1};
    std::vector<std::vector<int>> dist(h, std::vector<int>(w, INT_MAX));
    std::queue<std::tuple<int, int>> q;
    q.push({S[0], S[1]});
    dist[S[0]][S[1]] = 0;
    while (q.size()) {
      auto tpl = q.front(); q.pop();
      int uy = std::get<0>(tpl);
      int ux = std::get<1>(tpl);
      int ud = dist[uy][ux];
      for (int i = 0; i < 4; ++i) {
        int vy = uy + dlt[i];
        int vx = ux + dlt[i+1];
        int vd = ud + 1;
        // forward
        while (vy >= 0 && vy < h && vx >= 0 && vx < w &&
               G[vy][vx] == 0) {
          vy += dlt[i];
          vx += dlt[i+1];
          vd += 1;
        }
        vy -= dlt[i];
        vx -= dlt[i+1];
        vd -= 1;
        if (dist[vy][vx] > vd) {
          dist[vy][vx] = vd;
          q.push({vy, vx});
        }
      }
    }
    return dist[D[0]][D[1]] == INT_MAX ? -1 : dist[D[0]][D[1]];
  }
};

int main() {

  std::vector<std::vector<int>> G = {
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0}    
  };
  std::vector<int> src = {0, 4};
  std::vector<int> dst = {4, 4};

  // std::vector<std::vector<int>> G =
  //   {{0,0,0,0,1,0,0},
  //    {0,0,1,0,0,0,0},
  //    {0,0,0,0,0,0,0},
  //    {0,0,0,0,0,0,1},
  //    {0,1,0,0,0,0,0},
  //    {0,0,0,1,0,0,0},
  //    {0,0,0,0,0,0,0},
  //    {0,0,1,0,0,0,1},
  //    {0,0,0,0,1,0,0}};
  // std::vector<int> src = {0, 0};
  // std::vector<int> dst = {8, 6};

  Solution sln;
  printf("%d\n", sln.shortestDistance(G, src, dst));
  
  return 0;
}
