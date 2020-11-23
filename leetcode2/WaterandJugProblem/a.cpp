/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <cstdlib>
#include <algorithm>

// 0ms 100%
class Solution {
 private:
  int gcd(int x, int y) {
    if (x < y)
      std::swap(x, y);
    if (y == 0)
      return x;
    return gcd(y, x % y);
  }
 public:
  bool canMeasureWater(int x, int y, int z) {
    return z == 0 || z <= (int64_t)x + y && z % gcd(x, y) == 0;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  Solution sln;
  printb(sln.canMeasureWater(3, 5, 4));
  printb(sln.canMeasureWater(2, 6, 5));
  
  return 0;
}
