/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 20ms 100.00% 10.8MB 100.00%
// O(HW) O(W)
class Solution {
 public:
  int maximalRectangle(std::vector<std::vector<char>>& M) {
    if (M.empty() || M[0].empty())
      return 0;
    int rslt = 0;
    int h = M.size();
    int w = M[0].size();
    // count of continuous 1 from i to left, right, height
    std::vector<int> left(w, 0), right(w, w), height(w, 0);
    for (int y = 0; y < h; ++y) {
      int cur_left = 0;
      int cur_right = w;
      for (int x = w-1; x >= 0; --x) {
        // right
        if (M[y][x] == '1') {
          right[x] = std::min(right[x], cur_right);
        } else {
          right[x] = w;
          cur_right = x;
        }
      }
      for (int x = 0; x < w; ++x) {
        // left
        if (M[y][x] == '1') {
          height[x]++;
          left[x] = std::max(left[x], cur_left);          
        } else {
          height[x] = 0;
          left[x] = 0;
          cur_left = x + 1;
        }
        // rectangle
        rslt = std::max(rslt, (right[x] - left[x]) * height[x]);
      }
    }
    return rslt;
  }
};
 
int main() {

  std::vector<std::vector<char>> M = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}    
  };
  // std::vector<std::vector<char>> M = {
  //   {"1","0","1","0","0"},
  //   {"1","0","1","1","1"},
  //   {"1","1","1","1","1"},
  //   {"1","0","0","1","0"}
  // };

  Solution sln;
  printf("%d\n", sln.maximalRectangle(M));
  
  return 0;
}
