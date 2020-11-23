/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

// 1848ms 52.63% 10.3MB 37.04%
// O(NlgN) O(N)
class Solution {
 public:
  std::vector<int> kthSmallestPrimeFraction(std::vector<int>& V, int K) {
    std::priority_queue<std::pair<double, std::pair<int, int>>> pq;
    for (int j = 1; j < V.size(); ++j) {
      double p = V[0];
      double q = V[j];
      pq.push({-p/q, {0, j}});
    }
    while (--K) {
      auto pr = pq.top(); pq.pop();
      int i = pr.second.first;
      int j = pr.second.second;
      double p = V[i+1];
      double q = V[j];
      pq.push({-p/q, {i+1, j}});
    }
    auto pr = pq.top();
    return {V[pr.second.first], V[pr.second.second]};
  }
};

int main() {
  // std::vector<int> V = {1, 2, 3, 5};
  // int K = 3;
  std::vector<int> V = {1, 13, 17, 59};
  int K = 6;

  Solution sln;
  auto r = sln.kthSmallestPrimeFraction(V, K);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
