/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

// 36ms 82.40% 11.8MB 100.00%
// BFS
// O(HW) O(N)
class Solution {
 public:
  bool hasPath(std::vector<std::vector<int>>& G,
               std::vector<int>& S, std::vector<int>& D) {
    if (G.empty() || G[0].empty())
      return false;
    int h = G.size();
    int w = G[0].size();
    int dlt[5] = {-1, 0, 1, 0, -1};
    std::queue<std::pair<int, int>> q;
    q.push({S[0], S[1]});
    G[S[0]][S[1]] = -1;
    while (q.size()) {
      auto pr = q.front(); q.pop();
      int y = pr.first;
      int x = pr.second;
      // printf("%d %d\n", y, x);      
      if (y == D[0] && x == D[1])
        return true;
      for (int i = 0; i < 4; ++i) {
        int ny = y + dlt[i];
        int nx = x + dlt[i+1];
        // printf("_%d %d (%d)\n", ny, nx, i);                
        // forward ball
        while (ny >= 0 && ny < h &&
               nx >= 0 && nx < w && G[ny][nx] <= 0) {
          ny += dlt[i];
          nx += dlt[i+1];
          // printf("__%d %d\n", ny, nx);      
        }
        ny -= dlt[i];
        nx -= dlt[i+1];
        if (G[ny][nx] == 0) {
          q.push({ny, nx});
          G[ny][nx] = -1;
        }
      }
    }
    return false;
  }
};
// 0 4

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  // std::vector<std::vector<int>> G = {
  //   {0, 0, 1, 0, 0},
  //   {0, 0, 0, 0, 0},
  //   {0, 0, 0, 1, 0},
  //   {1, 1, 0, 1, 1},
  //   {0, 0, 0, 0, 0}    
  // };
  // std::vector<int> src = {0, 4};
  // std::vector<int> dst = {3, 2};

  std::vector<std::vector<int>> G =
    {{0,0,0,0,1,0,0},
     {0,0,1,0,0,0,0},
     {0,0,0,0,0,0,0},
     {0,0,0,0,0,0,1},
     {0,1,0,0,0,0,0},
     {0,0,0,1,0,0,0},
     {0,0,0,0,0,0,0},
     {0,0,1,0,0,0,1},
     {0,0,0,0,1,0,0}};
  std::vector<int> src = {0, 0};
  std::vector<int> dst = {8, 6};
  Solution sln;
  printb(sln.hasPath(G, src, dst));
  
  return 0;
}
