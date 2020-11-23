/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <numeric>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>

// 24ms 9.97%
class Solution {
 public:
  int minMoves2(std::vector<int>& V) {
    int n = V.size();
    std::sort(V.begin(), V.end());
    int median = V[n/2];
    return std::accumulate(
        V.begin(), V.end(), 0,
        [median](int a, int b){return a + std::abs(median-b);});    
  }
};

// 14
//
// 1 0 0 8 6
// 0 0 1 6 8
// 0 0 1 5 2
int main() {

  // std::vector<int> V = {1, 2, 3};
  std::vector<int> V = {1, 0, 0, 8, 6};

  Solution sln;
  printf("%d\n", sln.minMoves2(V));
  
  return 0;
}
