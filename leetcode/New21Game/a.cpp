/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

// 4ms 82.61% 9.5MB 58.33%
// prefix sum
// O(N) O(N)
class Solution {
 public:
  double new21Game(int N, int K, int W) {
    if (K == 0 || N >= K+W)
      return 1.0;
    std::vector<double> P(N+1, 0.0);
    P[0] = 1.0;
    double sum = 1.0;
    for (int i = 1; i <= N; ++i) {
      P[i] += sum / W;
      if (i < K)
        sum += P[i];
      if (i - W >= 0)
        sum -= P[i-W];
    }
    return std::accumulate(P.begin() + K,
                           P.end(),
                           0.0);        
  }
};

int main() {
  return 0;
}
