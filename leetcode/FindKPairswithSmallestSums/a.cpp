/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

// 
// 1 1 2
// 1 2 3
// 

// 1 2
// 2 2
// 1 3

// 1 1
// 1 1
// 2 1
// 1 3

// 16ms 43.87%
class Solution {
 public:
  std::vector<std::pair<int, int>> kSmallestPairs(
      std::vector<int>& U, std::vector<int>& V, int k) {
    std::vector<std::pair<int, int>> rslt;
    if (U.empty() || V.empty() || k <= 0)
      return rslt;
    auto cmp = [&U, &V](const std::pair<int, int>& a,
                        const std::pair<int, int>& b) {
      return U[a.first] + V[a.second] > U[b.first] + V[b.second];      
    };
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        decltype(cmp)> pq(cmp);
    pq.emplace(0, 0);
    while (k-- > 0 && pq.size()) {
      auto pr = pq.top(); pq.pop();
      rslt.push_back({U[pr.first], V[pr.second]});
      if (pr.first + 1 < U.size())
        pq.push({pr.first + 1, pr.second});
      if (pr.first == 0 && pr.second + 1 < V.size())
        pq.push({pr.first, pr.second + 1});
    }
    return rslt;
  }
};

int main() {
  // std::vector<int> U = {1, 7, 11};
  // std::vector<int> V = {2, 4, 6};
  // int k = 3;
  // std::vector<int> U = {1, 1, 2};
  // std::vector<int> V = {1, 2, 3};
  // int k = 2;
  // std::vector<int> U = {1, 2};
  // std::vector<int> V = {3};
  // int k = 3;
  std::vector<int> U = {1, 1, 2};
  std::vector<int> V = {1, 2, 3};
  int k = 10;

  Solution sln;
  auto rslt = sln.kSmallestPairs(U, V, k);
  for (const auto& p : rslt) {
    printf("%d %d\n", p.first, p.second);
  }
  printf("\n");
  
  return 0;
}
