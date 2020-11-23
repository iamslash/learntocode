/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

// 0ms 100.00% 13.2MB 20.72%
// prefix sum
// O(N) O(N)
class Solution {
 public:
  double new21Game(int N, int K, int W) {
    if (K == 0)
      return 1;
    std::vector<double> P(K+W, 0.0);
    P[0] = 1.0;
    double sum = 1.0;
    for (int i = 1; i < K + W; ++i) {
      P[i] += 1.0 / W * sum;
      if (i < K)
        sum += P[i];
      if (i - W >= 0)
        sum -= P[i-W];
    }
    return std::accumulate(P.begin() + K,
                           P.begin() + std::min(N+1, K+W),
                           0.0);        
  }
};

int main() {
  return 0;
}
