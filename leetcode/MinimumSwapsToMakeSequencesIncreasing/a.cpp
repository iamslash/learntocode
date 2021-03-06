/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//            i
//       A: 1 3 5 4
//       B: 1 2 3 7
// swapCnt: 1 2
// notsCnt: 0 

// 20ms 52.59% 14.5% 60.56%
// iterative dynamic programming
// O(N) O(1)
class Solution {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    int n = A.size(), swapCnt = 1, notsCnt = 0;
    for (int i = 1; i < n; ++i) {
      if (A[i-1] >= B[i] || B[i-1] >= A[i]) {
        swapCnt += 1;
      } else if (A[i-1] >= A[i] || B[i-1] >= B[i]) {
        int t = swapCnt;
        swapCnt = notsCnt + 1;
        notsCnt = t;
      } else {
        int minCnt = min(swapCnt, notsCnt);
        swapCnt = minCnt + 1;
        notsCnt = minCnt;
      }
    }
    return min(swapCnt, notsCnt);
  }
};
