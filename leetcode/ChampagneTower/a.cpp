/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // 24ms 29.27% 45.1MB 11.23%
// // dynamic programming
// // O(1) O(1)
// class Solution {
//  public:
//   double champagneTower(int p, int r, int c) {
//     std::vector<std::vector<double>> C(101, std::vector<double>(101, 0.0));
//     C[0][0] = p;
//     for (int y = 0; y <= r; ++y) {
//       for (int x = 0; x <= y; ++x) {
//         if (C[y][x] >= 1) {
//           double hd = (C[y][x] - 1) / 2.0;
//           C[y+1][x]   += hd;
//           C[y+1][x+1] += hd;
//           C[y][x]      = 1;
//         }
//       }
//     }
//     return C[r][c];
//   }
// };

// 4ms 98.58% 8.8MB 82.84%
// dynamic programming
// O(1) O(1)
class Solution {
 public:
  double champagneTower(int p, int r, int c) {
    std::vector<double> C(101, 0.0);
    C[0] = p;
    for (int i = 0; i < r; ++i) {
      for (int j = i; j >= 0; --j) {
        if (C[j] > 1) {
          double hd = (C[j] - 1.0) / 2.0;
          C[j+1] += hd;
          C[j]   = hd;
        } else {
          C[j] = 0;
        }
      }
    }
    return std::min(1.0, C[c]);
  }
};

int main() {

  Solution sln;
  printf("%lf\n", sln.champagneTower(1, 1, 1));
  printf("%lf\n", sln.champagneTower(2, 1, 1));
  
  return 0;
}
