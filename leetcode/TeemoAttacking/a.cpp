/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// O(N) O(1)
// 64ms 45.45%
class Solution {
 public:
  int findPoisonedDuration(std::vector<int>& V, int D) {
    if (V.empty())
      return 0;
    if (V.size() == 1)
      return D;
    int rslt = 0;
    for (int i = 1; i < V.size(); ++i) {
      int diff = V[i] - V[i-1];
      rslt += std::min(D, diff);
    }
    return rslt + D;
  }
};

int main() {
  // std::vector<int> V = {1, 4};
  std::vector<int> V = {1, 2};
  int D = 2;

  Solution sln;
  printf("%d\n", sln.findPoisonedDuration(V, D));
  
  return 0;
}
