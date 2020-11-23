/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

// x..x
// ...x
// ...x
//
// 4ms 98.90%
class Solution {
 public:
  int countBattleships(std::vector<std::vector<char>>& B) {
    int rslt = 0;
    for (int y = 0; y < B.size(); ++y) {
      for (int x = 0; x < B[0].size(); ++x) {
        if (B[y][x] == 'X' &&
            (y == 0 || B[y-1][x] != 'X') &&
            (x == 0 || B[y][x-1] != 'X'))
          rslt++;
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<std::vector<char>> B = {
    {'X', '.', '.', 'X'},
    {'.', '.', '.', 'X'},
    {'.', '.', '.', 'X'},
  };

  Solution sln;
  printf("%d\n", sln.countBattleships(B));
  
  return 0;
}
