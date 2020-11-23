/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <set>

// 776ms 19.50% 98.4MB 58.82%
// partial sum
// O(W^2HlgH) O(H)
class Solution {
 public:
  int maxSumSubmatrix(std::vector<std::vector<int>>& M, int k) {
    int h = M.size(), w = M[0].size(), glbmax = INT_MIN;
    if (h == 0)
      return 0;
    for (int i = 0; i < w; i++) {
      // horizontal sums
      std::vector<int> wSums(h, 0);
      for (int j = i; j < w; j++) {
        for (int y = 0; y < h; y++) {
          wSums[y] += M[y][j];
        }
        std::set<int> psSet;
        psSet.insert(0);
        int cum = 0, locMax = INT_MIN;
        for (int wSum : wSums) {
          cum += wSum;
          auto it = psSet.lower_bound(cum-k);
          if (it != psSet.end())
            locMax = std::max(locMax, cum - *it);
          psSet.insert(cum);
        }
        glbmax = std::max(glbmax, locMax);
        if (glbmax == 8)
          printf("i: %d, j: %d\n", i, j);
      }
    }
    return glbmax;
  }
};

int main() {
  std::vector<std::vector<int>> M = {
    {5, -4, -3, 4},
    {-3,-4,4,5},
    {5,1,5,-4}
  };
  int k = 8;

  Solution sln;
  printf("%d\n", sln.maxSumSubmatrix(M, k));
  
  
  return 0;
}
