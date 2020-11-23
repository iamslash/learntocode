/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 8ms 35.43% 82.MB 100.00%
// xor
// O(N) O(N)
class Solution {
 public:
  int oddCells(int h, int w, vector<vector<int>>& I) {
    vector<vector<int>> A(h, vector<int>(w, 0));
    for (auto& yx : I) {
      for (int y = 0; y < h; ++y)
        A[y][yx[1]] ^= 1;
      for (int x = 0; x < w; ++x)
        A[yx[0]][x] ^= 1;
    }
    
    int ans = 0;
    for (int y = 0; y < h; ++y)
      ans += count_if(A[y].begin(), A[y].end(), [](int a){return a & 1;});
    return ans;
  }
};
