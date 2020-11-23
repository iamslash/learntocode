/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>


// 16ms 94.01% 10.3MB 59.17%
// O(HW) O(1)
class Solution {
 public:
  bool validWordSquare(std::vector<std::string>& W) {
    int h = W.size();
    for (int y = 0; y < h; ++y) {
      int w = W[y].size();
      for (int x = 0; x < w; ++x) {
        if (x >= h || y >= W[x].size() || W[y][x] != W[x][y])
          return false;
      }
    }
    return true;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  // std::vector<std::string> W =
  // {
  //   "abcd",
  //   "bnrt",
  //   "crmy",
  //   "dtye"    
  // };
  // std::vector<std::string> W =
  // {
  //   "abcd",
  //   "bnrt",
  //   "crm",
  //   "dt"
  // };
  // std::vector<std::string> W =
  // {
  //   "ball",
  //   "area",
  //   "read",
  //   "lady"
  // };
  std::vector<std::string> W =
  {
    "ball",
    "asee",
    "let",
    "lep"
  };


  

  Solution sln;
  printb(sln.validWordSquare(W));
  
  
  return 0;
}
