/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>

// // 36ms 91.61% 17.6MB 84.20%
// // dfs
// // O(NlgN) O(N)
// class Solution {
//  private:
//   void dfs(std::vector<std::vector<int>>& G,
//            std::set<std::pair<int, int>>& path,
//            int uy, int ux) {
//     G[uy][ux] = -1;
//     path.emplace(uy, ux);
//     int h = G.size();
//     int w = G[0].size();
//     int ds[5] = {-1, 0, 1, 0, -1};
//     for (int i = 0; i < 4; ++i) {
//       int vy = uy + ds[i];
//       int vx = ux + ds[i+1];
//       if (vy < 0 || vy >= h || vx < 0 || vx >= w ||
//           G[vy][vx] <= 0)
//         continue;
//       dfs(G, path, vy, vx);
//     }
//   }
//   void extract(std::set<std::string>& islands,
//                std::set<std::pair<int, int>>& path) {
//     int oy = INT_MAX;
//     int ox = INT_MAX;
//     for (auto it = path.begin(); it != path.end(); ++it) {
//       oy = std::min(oy, it->first);
//       ox = std::min(ox, it->second);
//     }
//     std::string s;
//     for (auto it = path.begin(); it != path.end(); ++it) {
//       s += (it->first - oy + '0');
//       s += ',';
//       s += (it->second - ox + '0');
//       s += ',';
//     }
//     islands.insert(s);
//   }
//  public:
//   int numDistinctIslands(std::vector<std::vector<int>>& G) {
//     if (G.empty() || G[0].empty())
//       return 0;
//     std::set<std::string> islands;
//     int h = G.size();
//     int w = G[0].size();
//     for (int y = 0; y < h; ++y) {
//       for (int x = 0; x < w; ++x) {
//         if (G[y][x] <= 0)
//           continue;
//         std::set<std::pair<int, int>> path;
//         dfs(G, path, y, x);
//         extract(islands, path);
//       }
//     }
//     return islands.size();
//   }
// };

// 16ms 100.00%
// O(N) O(N)
class Solution {
 private:
  void dfs(std::vector<std::vector<int>>& G,
           std::string& path,
           char c, int y, int x) {
    int h = G.size();
    int w = G[0].size();
    if (y < 0 || y >= h || x < 0 || x >= w ||
        G[y][x] <= 0)
      return;
    path.push_back(c);
    G[y][x] = 0;
    dfs(G, path, 'u', y - 1, x);
    dfs(G, path, 'r', y    , x + 1);
    dfs(G, path, 'd', y + 1, x);
    dfs(G, path, 'l', y    , x - 1);
    path.push_back('e');
  }
 public:
  int numDistinctIslands(std::vector<std::vector<int>>& G) {
    std::unordered_set<std::string> islands;
    for (int y = 0; y < G.size(); ++y) {
      for (int x = 0; x < G[0].size(); ++x) {
        if (G[y][x] <= 0)
          continue;
        std::string path;
        dfs(G, path, 's', y, x);
        printf("'%s'\n", path.c_str());
        if (path.size())
          islands.insert(path);
      }
    }
    return islands.size();
  }
};

int main() {
  // std::vector<std::vector<int>> G = {
  //   {1,1,0,0,0},
  //   {1,1,0,0,0},
  //   {0,0,0,1,1},
  //   {0,0,0,1,1}
  // };
  std::vector<std::vector<int>> G = {
    {0,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,0},{0,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,0,0,0},{0,1,0,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0},{1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1}
  };
  Solution sln;
  printf("%d\n", sln.numDistinctIslands(G));
  
  return 0;
}
