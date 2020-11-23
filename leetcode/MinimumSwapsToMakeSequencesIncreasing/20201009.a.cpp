/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//    A: 1 3 5 4
//    B: 1 2 3 7
// swap: 0
// nots: 0

// 8ms 99.27% 9.1MB 79.32%
// O(N) O(1)
class Solution {
 public:
  int minSwap(std::vector<int>& A, std::vector<int>& B) {
    int swap = 1, nots = 0, n = A.size();
    for (int i = 1; i < n; ++i) {      
      if (A[i-1] >= B[i] || B[i-1] >= A[i]) {
        // should swap i, i-1
        swap += 1;
      } else if (A[i-1] >= A[i] || B[i-1] >= B[i]) {
        // should swap i
        int t = swap;
        swap = nots + 1;
        nots = t;
      } else {
        // swap or not swap
        int minval = std::min(swap, nots);
        nots = minval;
        swap = minval + 1;
      }
    }
    return std::min(swap, nots);
  }
};

int main() {

  std::vector<int> A = {1, 3, 5, 4};
  std::vector<int> B = {1, 2, 3, 7};

  Solution sln;
  printf("%d\n", sln.minSwap(A, B));
  
  return 0;
}
