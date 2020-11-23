/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

// C[0] = 1
// C[1] = C[0] + 9
// C[2] = C[1] + 9 * 9
// C[3] = C[2] + 9 * 9 * 8
// C[4] = C[3] + 9 * 9 * 8 * 7
class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0)
      return 1;
    int cp = 9;  // cumulative product
    int cs = 10;  // cumulative sum
    for (int i = 0; i < n-1 && i < 9; ++i) {
      cp *= (9-i);
      cs += cp;
    }
    return cs;
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.countNumbersWithUniqueDigits(2));  
  printf("%d\n", sln.countNumbersWithUniqueDigits(3));  // 739
  printf("%d\n", sln.countNumbersWithUniqueDigits(4));  
  printf("%d\n", sln.countNumbersWithUniqueDigits(5));  
  return 0;
}
