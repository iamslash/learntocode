/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// 132ms 44.11% 30.8MB 43.52%
// dijkstra algorithm
// O(ElgN) O(N)
class Solution {
 public:
  int networkDelayTime(std::vector<std::vector<int>>& T,
                       int N, int K) {
    int rslt = 0;
    std::unordered_map<int, std::unordered_map<int, int>> grid;
    std::vector<int> dist(N, INT_MAX);
    std::priority_queue<std::pair<int, int>> pque;

    // set grid
    for (auto& v : T) 
      grid[v[0]-1][v[1]-1] = v[2];
    pque.push({0, K-1});
    dist[K-1] = 0;
    while (!pque.empty()) {
      auto pr = pque.top(); pque.pop();
      int d2u = -pr.first;
      int u = pr.second;
      for (auto& pr : grid[u]) {
        int v   = pr.first;
        int duv = pr.second;
        if (d2u + duv >= dist[v])
          continue;
        int d2v = d2u + duv;
        dist[v] = d2v;
        pque.push({-d2v, v});
      }
    }
    // for (int d : dist)
    //   printf("%d ", d);
    // printf("\n");
         
    int r = *std::max_element(dist.begin(), dist.end());
    if (r == INT_MAX)
      r = -1;
    return r;
  }
};

int main() {
  
  // std::vector<std::vector<int>> T = {
  //   {1,2,1},
  //   {2,3,2},
  //   {1,3,2}
  // }; 
  // int N = 3;
  // int K = 1;
  
  // std::vector<std::vector<int>> T = {
  //   {2,1,1},
  //   {2,3,1},
  //   {3,4,1}
  // }; 
  // int N = 4;
  // int K = 2;

  // std::vector<std::vector<int>> T = {
  //   {1,2,1},
  //   {2,1,3}
  // };
  // int N = 2;
  // int K = 2;

  std::vector<std::vector<int>> T = 
      {
        {1,2,1},
        {2,3,2},
        {1,3,4}
      };
  int N = 3;
  int K = 1;

  Solution sln;
  printf("%d\n", sln.networkDelayTime(T, N, K));
  
  return 0;
}
