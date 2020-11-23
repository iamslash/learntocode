/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 4ms 99.10%
class Solution {
 public:
  int maxProduct(std::vector<int>& V) {
    int rslt = V[0];
    int lastmin = V[0];
    int lastmax = V[0];
    for (int i = 1; i < V.size(); ++i) {
      int num = V[i];
      int tmin = lastmin * num;
      int tmax = lastmax * num;
      lastmin = std::min(num, std::min(tmin, tmax));
      lastmax = std::max(num, std::max(tmin, tmax));
      rslt = std::max(rslt, lastmax);
      // printf("i: %d, num: %d, lastmin: %d, lastmax: %d\n", i, num, lastmin, lastmax);
    }
    return rslt;
  }
};

int main() {
  // std::vector<int> V = {2, 3, -2, 4};
  std::vector<int> V = {-2, 0, -1};
  Solution sln;
  printf("%d\n", sln.maxProduct(V));
  
  return 0;
}
