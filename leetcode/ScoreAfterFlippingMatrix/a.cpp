/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/score-after-flipping-matrix/description/

#include <cstdio>
#include <vector>
#include <cmath>

// O(N^2) O(1)
// 4ms 45.85%
class Solution {
 public:
  int matrixScore(std::vector<std::vector<int>>& B) {
    int h = B.size();
    int w = B[0].size();
    int r = 0;
    for (int x = 0; x < w; ++x) {
      int sum = 0;
      for (int y = 0; y < h; ++y) {
        sum += B[y][x] ^ B[y][0];
      }
      r += std::max(sum, h-sum) * (1 << w-x-1);
    }
    return r;
  }
};

// O(N^2) O(1)
// 4ms 45.85%
// class Solution {
//  public:
//   int matrixScore(std::vector<std::vector<int>>& B) {
//     int h = B.size();
//     int w = B[0].size();
//     // set first column as 1
//     for (int y = 0; y < h; ++y) {
//       if (B[y][0] == 1)
//         continue;
//       for (int x = 0; x < w; ++x){
//         B[y][x] = ~B[y][x] & 0x01;                    
//       }
//     }
//     // get count 0 or 1
//     for (int y = 1; y < h; ++y) {
//       for (int x = 0; x < w; ++x) {
//         B[0][x] += B[y][x];
//       }
//     }
//     // calculate sum
//     int r = B.size() * std::pow(2, w-1);
//     for (int x = 1; x < w; ++x) {
//       int n = std::max(B[0][x], h - B[0][x]);
//       r += n * std::pow(2, w-x-1);
//     }
//     return r;
//   }
// };

int main() {
  std::vector<std::vector<int>> B = {
    {0, 0, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
  };
  
  Solution s;
  printf("%d\n", s.matrixScore(B));
  return 0;
}
