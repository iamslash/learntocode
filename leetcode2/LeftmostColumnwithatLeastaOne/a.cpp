/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// // Wrong Answer: You made too many calls to BinartMatrix.get()
// class Solution {
//  public:
//   int leftMostColumnWithOne(BinaryMatrix &bm) {
//     int h = bm.dimensions()[0];
//     int w = bm.dimensions()[1];
//     for (int x = 0; x < w; ++x) {
//       for (int y = 0; y < h; ++y) {
//         if (bm.get(y, x) == 1)
//           return x;
//       }
//     }
//     return -1;
//   }
// };

// 16ms 14.05% 8.3MB 20.68%
class Solution {
 public:
  int leftMostColumnWithOne(BinaryMatrix &bm) {
    int h = bm.dimensions()[0];
    int w = bm.dimensions()[1];
    int ans = -1, y = 0, x = w - 1;
    while (y < h && x >= 0) {
      if (bm.get(y, x) == 1) {
        ans = x;
        x--;
      } else {
        y++;
      }
    }
    return ans;
  }
};
