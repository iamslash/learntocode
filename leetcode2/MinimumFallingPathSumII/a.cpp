/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

// 1 2 3
// 4 5 6
// 7 8 9

// 68ms 71.65% 13.3MB 50.06%
// 1st min, 2nd min
// O(HW) O(1)
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& A) {
    int h = A.size(), w = A[0].size();
    int cumMin1st = 0, cumMin1stJ = -1, cumMin2nd = 0;
    for (int i = 0; i < h; ++i) {
      int min1st = 20000, min1stJ = -1, min2nd = 20000;
      for (int j = 0; j < w; ++j) {
        int cumMinVal = (j == cumMin1stJ) ? cumMin2nd : cumMin1st;
        if (A[i][j] + cumMinVal < min1st) {
          min2nd = min1st;
          min1st = A[i][j] + cumMinVal;
          min1stJ = j;
        } else {
          min2nd = min(min2nd, A[i][j] + cumMinVal);
        }
      }
      cumMin1st = min1st, cumMin1stJ = min1stJ, cumMin2nd = min2nd;
    }
    return cumMin1st;
  }
};

int main() {
  return 0;
}
