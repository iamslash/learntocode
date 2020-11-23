/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

// 20ms 55.67% 16.2MB 45.83%
// BFS
// O(V+E) O(HW)
class Solution {
 public:
  std::string findShortestWay(std::vector<std::vector<int>>& G,
                         std::vector<int>& B, std::vector<int>& H) {
    if (G.empty() || G[0].empty())
      return "";
    int h = G.size();
    int w = G[0].size();    
    int dlt[5] = {-1, 0, 1, 0, -1};
    std::string dir = "urdl";
    std::vector<std::vector<int>> dist(h, std::vector<int>(w, INT_MAX));
    std::vector<std::vector<std::string>> path(h, std::vector<std::string>(w, "z"));    
    std::queue<std::tuple<int, int, int, std::string>> q;
    q.push({B[0], B[1], 0, ""});
    while (q.size()) {
      auto        tpl = q.front(); q.pop();
      int         uy  = std::get<0>(tpl);
      int         ux  = std::get<1>(tpl);
      int         ud  = std::get<2>(tpl);
      std::string up  = std::get<3>(tpl);
      if ((dist[uy][ux] < ud) ||
          (dist[uy][ux] == ud && path[uy][ux] <= up))
        continue;
      // printf("%d %d %d '%s' | %d '%s'\n", uy, ux, ud, up.c_str(), dist[uy][ux], path[uy][ux].c_str());
      // set dist, path
      dist[uy][ux] = ud;
      path[uy][ux] = up;
      if (uy == H[0] && ux == H[1])
        continue;
      for (int i = 0; i < 4; ++i) {
        int         vy = uy;
        int         vx = ux;
        int         vd = ud;
        std::string vp = up;
        while ( vy >= 0 && vy < h && vx >= 0 && vx < w &&
                G[vy][vx] == 0 && (vy != H[0] || vx != H[1])) {
          vy += dlt[i];
          vx += dlt[i+1];
          vd += 1;
        }
        if (vy != H[0] || vx != H[1]) {
          vy -= dlt[i];
          vx -= dlt[i+1];
          vd -= 1;
        }
        if (vd > ud)
          vp.push_back(dir[i]);
        q.push({vy, vx, vd, vp});
        // printf("  %d %d %d '%s'\n", vy, vx, vd, vp.c_str());
      }
    }
    return dist[H[0]][H[1]] == INT_MAX ? "impossible" : path[H[0]][H[1]];
  }
};

int main() {

  std::vector<std::vector<int>> G = {
    {0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0}    
  };
  std::vector<int> B = {4, 3};
  std::vector<int> H = {0, 1};
  Solution sln;
  printf("%s\n", sln.findShortestWay(G, B, H).c_str());

  return 0;
}
