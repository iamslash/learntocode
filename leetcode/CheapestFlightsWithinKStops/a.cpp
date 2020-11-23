/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#include <unordered_map>
// 36ms 42.47% 13.7MB 33.32%
// dijkstra algorithm
// O(ElgV) O(V)
class Solution {
 public:
  int findCheapestPrice(int n, std::vector<std::vector<int>>& F,
                        int src, int dst, int k) {
    std::unordered_map<int, std::unordered_map<int, int>> G;
    for (auto& f : F)
      G[f[0]][f[1]] = f[2];
    std::priority_queue<std::tuple<int, int, int>> pq;
    pq.push({0, src, k+1});
    while (pq.size()) {
      auto tpl = pq.top(); pq.pop();
      int d2u = -std::get<0>(tpl);
      int u   = std::get<1>(tpl);
      int utl = std::get<2>(tpl);
      if (u == dst)
        return d2u;
      if (utl == 0)
        continue;
      // visit v nodes
      for (auto& pr : G[u])
        pq.push({-(d2u + pr.second), pr.first, utl-1});
    }
    return -1;
  }
};

int main() {

  int n = 3;
  std::vector<std::vector<int>> F = {{0,1,100},{1,2,100},{0,2,500}};
  int src = 0;
  int dst = 2;
  int k = 0;

  Solution sln;
  printf("%d\n", sln.findCheapestPrice(n, F, src, dst, k));
  
  return 0;
}
