/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

// zdz
// DDDDD!UUUUURRR!DDDDDLLL!
// DDDDD!UUUUURRR!DDDDLLLD!
// d: u(0, 3)
// z: v(5, 0)

// 4ms 59.78% 8.3MB 100.00%
// manhatan distance
// O(S) O(S)
class Solution {
 public:
  std::string alphabetBoardPath(std::string s) {
    std::string ans;
    // current position [y][x]
    int uy = 0, ux = 0;
    for (char c : s) {
      int vy = (c - 'a') / 5;
      int vx = (c - 'a') % 5;
      if (uy - vy > 0)
        ans += std::string(uy - vy, 'U');
      if (vx - ux > 0)
        ans += std::string(vx - ux, 'R');
      if (ux - vx > 0)
        ans += std::string(ux - vx, 'L');
      if (vy - uy > 0)
        ans += std::string(vy - uy, 'D');
      ans += '!';
      uy = vy, ux = vx;
    }
    return ans;
  }
};

int main() {
  return 0;
}
