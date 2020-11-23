/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//        x
// B:   0 1 1 0
//      0 1 1 0
//    y 1 0 0 1
//      1 0 0 1

// B:   0 1
//      1 0

// 40ms 8.33% 10.2MB 80.95%
// O(N^2) O(1)
class Solution {
 public:
  int movesToChessboard(vector<vector<int>>& B) {
    int n = B.size(), rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        if (B[0][0] ^ B[y][0] ^ B[0][x] ^ B[y][x])
          return -1;
      }
    }
    for (int i = 0; i < n; ++i) {
      rowSum += B[0][i];
      colSum += B[i][0];
      if (B[i][0] == i % 2)
        rowSwap++;
      if (B[0][i] == i % 2)
        colSwap++;
    }
    if (rowSum != n/2 && rowSum != (n+1)/2)
      return -1;
    if (colSum != n/2 && colSum != (n+1)/2)
      return -1;
    if (n % 2) {
      if (colSwap % 2)
        colSwap = n - colSwap;
      if (rowSwap % 2)
        rowSwap = n - rowSwap;
    } else {
      colSwap = min(colSwap, n - colSwap);
      rowSwap = min(rowSwap, n - rowSwap);
    }
    return (rowSwap + colSwap) / 2;
  }
};
