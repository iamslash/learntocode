/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//    0 1 2 3 4
// B: 0 0 2 3 4
//            i
// C: 0 0 2 3 0

// 9ms 97.53% 9.1MB 89.74%
// dynamic programming
// O(N) O(N)
class Solution {
 public:
  int deleteAndEarn(std::vector<int>& V) {
    if (V.empty())
      return 0;
    int n = *std::max_element(V.begin(), V.end());
    std::vector<int> B(n+1, 0);
    for (int a : V)
      B[a] += a;
    std::vector<int> C(n+1, 0);
    C[1] = B[1];
    for (int i = 2; i <= n; ++i)
      C[i] = std::max(B[i] + C[i-2], C[i-1]);
    return C[n];
  }
};

int main() {

  std::vector<int> V = {3, 4, 2};
  // std::vector<int> V = {2, 2, 3, 3, 3, 4};

  Solution sln;
  printf("%d\n", sln.deleteAndEarn(V));
  
  return 0;
}
