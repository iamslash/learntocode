/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

// k:2 x: 4
// 1 2 3 4 5
//     i
//       j
//     

// 104ms 98.26% 13.4MB 100.00%
// O(lgN+K) O(1)
class Solution {
 public:
  std::vector<int> findClosestElements(std::vector<int>& V, int k, int x) {
    int n = V.size(), l = 0, r = n - k, m;
    int idx = std::lower_bound(V.begin(), V.end(), x) - V.begin();
    int i = idx - 1, j = idx;
    while (k--) {
      if (i < 0 || (j < V.size() && std::abs(V[i] - x) > std::abs(V[j]-x)))
        ++j;
      else
        --i;
    }
    return std::vector<int>(V.begin() + i + 1, V.begin() + j);
  }
};

int main() {
  //std::vector<int> V = {1, 2, 3, 4, 5};
  std::vector<int> V = {0,2,2,3,4,6,7,8,9,9};  // 3 4 6 7
  Solution sln;
  // auto rslt = sln.findClosestElements(V, 2, 4);
  auto rslt = sln.findClosestElements(V, 4, 5);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
