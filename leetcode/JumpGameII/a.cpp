/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

//      i
// A: 2 3 1 1 4
//            j
//    ----
//      ------
//        --
//          --
//


//                  i
// A: 7 0 9 6 9 6 1 7 9 0 1 2 9 0 3
//                  j
//                                k
//    --------------
//        ------------------
//            ------------------

// 8ms 94.03% 8.2MB 100.00%
// exchange ladder
// O(N) O(1)
class Solution {
 public:
  int jump(std::vector<int>& A) {
    int ans = 0, n = A.size();
    for (int i = 0, j = 0, k = 0; i < n-1; ++i) {
      k = std::max(k, i + A[i]);
      if (i == j) {
        j = k;
        ans++;
      }
    }
    return ans;
  }
};
