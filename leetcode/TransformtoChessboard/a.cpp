/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

class Solution {
 public:
  int movesToChessboard(std::vector<std::vector<int>>& B) {
    
  }
};

int main() {

  std::vector<std::vector<int>> B = {
    {0,1,1,0},
    {0,1,1,0},
    {1,0,0,1},
    {1,0,0,1}
  };
  Solution sln;
  printf("%d\n", sln.movesToChessboard(B));
  
  return 0;
}
