/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

// 36ms 28.21%
// 2.8MB 40.00%
// O(N) O(N)
class Solution {
 public:
  double mincostToHireWorkers(
      std::vector<int>& Q, std::vector<int>& W, int K) {
    int n = Q.size();
    std::vector<std::vector<double>> ratios;  // q/w, q
    for (int i = 0; i < n; ++i)
      ratios.push_back({(double)W[i] / Q[i], (double)Q[i]});
    std::sort(ratios.begin(), ratios.end());
    double rslt = std::numeric_limits<double>::max();
    double qsum = 0;  // sum of quality in k group
    std::priority_queue<int> pq;
    for (auto r : ratios) {
      qsum += r[1];
      pq.push(r[1]);
      if (pq.size() > K) {
        qsum -= pq.top(); pq.pop();
      }
      if (pq.size() == K) {
        rslt = std::min(rslt, qsum * r[0]);
      }
    }
    return rslt;
  }
};

int main() {
  // std::vector<int> Q = {10, 20, 5};
  // std::vector<int> W = {70, 50, 30};
  // int K = 2;
  std::vector<int> Q = {3, 1, 10, 10, 1};
  std::vector<int> W = {4, 8, 2, 2, 7};
  int K = 3;
  Solution sln;
  printf("%lf\n", sln.mincostToHireWorkers(Q, W, K));
  
  return 0;
}
