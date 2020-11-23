/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// 0ms 100.00% 8.2MB 70.45%
// O(lgY) O(1)
class Solution {
 public:
  int brokenCalc(int X, int Y) {
    int ans = 0;
    while (X < Y) {
      ans++;
      if (Y & 1)
        Y += 1;
      else
        Y /= 2;
    }
    return ans + X - Y;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.brokenCalc(2, 3));
  printf("%d\n", sln.brokenCalc(5, 8));
  printf("%d\n", sln.brokenCalc(3, 10));
  printf("%d\n", sln.brokenCalc(1024, 1));
  
  return 0;
}
