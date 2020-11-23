/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

// 0 0 0 0 0

// 0 2 0 0 -2
// 0 2 2 2  0

// p[0] = r[0]
// p[1] = p[0] + r[1]
// p[2] = p[1] + r[2]
// ...
// p[n] = p[n-1] + r[n]

// 84ms 79.48% 15.1MB 81.82%
// partial sum
// O(U) O(1)
class Solution {
 public:
  std::vector<int> getModifiedArray(int n, std::vector<std::vector<int>>& U) {
    std::vector<int> rslt(n, 0);
    for (auto& l : U) {
      int i = l[0], j = l[1], k = l[2];
      rslt[i] += k;
      if (j < n-1)
        rslt[j+1] -= k;
    }
    std::partial_sum(rslt.begin(), rslt.end(), rslt.begin());
    return rslt;
  }
};

int main() {
  std::vector<std::vector<int>> U = {
    {1, 3, 2},
    {2, 4, 3},
    {0, 2,-2}};
  int n = 5;
  Solution sln;
  auto r = sln.getModifiedArray(n, U);
  for (int a : r)
    printf("%d ", a);
  printf("\n");  
  return 0;
}
