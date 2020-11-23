// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

// s0 <-cooldown- s2
//  \             ^
//   buy        sell
//    \         /  
//     ->  s1  /
class Solution {
 public:
  int maxProfit(const std::vector<int>& P) {
    if (P.size() <= 1)
      return 0;
    int n = P.size();
    std::vector<int> s0(n, 0);
    std::vector<int> s1(n, 0);
    std::vector<int> s2(n, 0);
    s0[0] = 0;
    s1[0] = -P[0];
    s2[0] = std::numeric_limits<int>::min();
    for (int i = 1; i < n; ++i) {
      s0[i] = std::max(s0[i-1], s2[i-1]);
      s1[i] = std::max(s1[i-1], s0[i-1]-P[i]);
      s2[i] = s1[i-1]+P[i];
    }
    return std::max(s0[n-1], s2[n-1]);
  }
};

int main() {
  std::vector<int> P = {1, 2, 3, 0, 2};

  Solution sln;
  printf("%d\n", sln.maxProfit(P));

  return 0;
}
