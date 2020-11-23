/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 0ms 100.00% 8.5MB 100.00%
// brute force
// O(I) O(1)
class Solution {
 public:
  bool isRobotBounded(std::string I) {
    int x = 0, y = 0, i = 0;
    std::vector<std::vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (char &c : I) {
      if (c == 'R') {
        i = (i + 1) % 4;
      } else if (c == 'L') {
        i = (i + 3) % 4;
      } else {
        x += dir[i][0], y += dir[i][1];
      }
    }
    return (x == 0 && y == 0) || i > 0;
  }
};

int main() {
  return 0;
}
