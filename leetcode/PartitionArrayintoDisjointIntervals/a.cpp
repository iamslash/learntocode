/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//  A: 5 0 3 8 6
//               i
//         p
// lm: 5
// gm: 8

// 40ms 95.48% 10.8MB 78.75%
// O(N) O(1)
class Solution {
 public:
  int partitionDisjoint(std::vector<int>& A) {
    int n = A.size(), locmax = A[0], glbmax = locmax, prtidx = 0;
    for (int i = 1; i < n; ++i) {
      if (locmax > A[i]) {
        locmax = glbmax;
        prtidx = i;
      } else {
        glbmax = std::max(glbmax, A[i]);
      }
      printf("i: %d, p: %d, locmax: %d, glbmax: %d\n",
             i, prtidx, locmax, glbmax);
    }
    return prtidx + 1;
  }
};

int main() {
  std::vector<int> A = {5, 0, 3, 8, 6};
  // std::vector<int> A = {1, 1, 1, 0, 6, 12};
  // std::vector<int> A = {1, 1};
  Solution sln;
  printf("%d\n", sln.partitionDisjoint(A));
  return 0;
}
