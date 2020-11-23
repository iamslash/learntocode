/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// A: 1 3 5 4
// B: 1 2 3 7

// A: 4 5
// B: 1 2
// 12ms 99.56% 14.5MB 16.50%
// dynamic programming
// O(N) O(1)
class Solution {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    int swapCnt = 1, notsCnt = 0, n = A.size();
    for (int i = 1; i < n; ++i) {
      if (A[i-1] >= B[i] || B[i-1] >= A[i]) {
        swapCnt++;
      } else if (A[i-1] >= A[i] || B[i-1] >= B[i]) {
        swap(swapCnt, notsCnt);
        swapCnt++;
      } else {
        int minCnt = min(swapCnt, notsCnt);
        swapCnt = minCnt + 1;
        notsCnt = minCnt;
      }
    }
    return min(swapCnt, notsCnt);
  }
};
