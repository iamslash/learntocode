/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <limits>

// 36ms 100.00% 10.9MB 78.13%
// O(NlgN) O(N)
class Comp {
 public:
  bool operator()(const std::pair<int, std::pair<int, int>>& a,
                  const std::pair<int, std::pair<int, int>>& b) {
    return a.first > b.first;
  }
};
class Solution {
 public:
  int trapRainWater(std::vector<std::vector<int>>& G) {    
    if (G.size() < 3 || G[0].size() < 3)
      return 0;
    int h = G.size();
    int w = G[0].size();
    // printf("%d %d\n", h, w);
    std::priority_queue<
      std::pair<int, std::pair<int, int>>,
      std::vector<std::pair<int, std::pair<int, int>>>,
      Comp> pq;
    int dy[4] = {-1, 0, 1,  0};
    int dx[4] = { 0, 1, 0, -1};
    for (int x = 0; x < w; ++x) {
      pq.push({G[0][x], {0,x}});
      pq.push({G[h-1][x], {h-1,x}});
      G[0][x] *= -1;
      G[h-1][x] *= -1;
    }
    for (int y = 1; y < h-1; ++y) {
      pq.push({G[y][0], {y, 0}});
      pq.push({G[y][w-1], {y, w-1}});
      G[y][0] *= -1;
      G[y][w-1] *= -1;
    }
    int sum = 0, maxh = std::numeric_limits<int>::min();
    while (!pq.empty()) {
      auto pr = pq.top(); pq.pop();      
      int uh = pr.first;
      int uy = pr.second.first;
      int ux = pr.second.second;
      maxh = std::max(maxh, uh);
      // printf("%d [%d,%d]\n", h, y, x);
      for (int i = 0; i < 4; ++i) {
        int vy = uy + dy[i];
        int vx = ux + dx[i];
        // printf("  [%d,%d]\n", ny, nx);        
        if (vy < 0 || vy >= h || vx < 0 || vx >= w || G[vy][vx] < 0)
          continue;
        // printf("    %d [%d,%d]\n", G[ny][nx], ny, nx);
        int vh = G[vy][vx];
        if (vh < maxh)
          sum += maxh - vh;
        pq.push({vh, {vy, vx}});
        G[vy][vx] = std::numeric_limits<int>::min();
      }      
    }
    return sum;
  }
};

int main() {

  // std::vector<std::vector<int>> G =
  //     {
  //       {1,4,3,1,3,2},
  //       {3,2,1,3,2,4},
  //       {2,3,3,2,3,1}
  //     };
  // std::vector<std::vector<int>> G = {
  //   {12,13,1,12},
  //   {13,4,13,12},
  //   {13,8,10,12},
  //   {12,13,12,12},
  //   {13,13,13,13}
  // };
  std::vector<std::vector<int>> G = {
    {9,9,9,9,9,9,8,9,9,9,9},
    {9,0,0,0,0,0,1,0,0,0,9},
    {9,0,0,0,0,0,0,0,0,0,9},
    {9,0,0,0,0,0,0,0,0,0,9},
    {9,9,9,9,9,9,9,9,9,9,9}
  };

  

  Solution sln;
  printf("%d\n", sln.trapRainWater(G));
  
  return 0;
}
