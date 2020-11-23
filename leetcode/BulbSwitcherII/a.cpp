/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//   0 1
// 0 1 1
// 1 1 2 
// 2 1 3
// 3 1 4

// 4ms 100.00% 8.7MB 57.14%
// O(1) O(1)
class Solution {
 public:
  int flipLights(int n, int m) {
    if (m == 0)
      return 1;
    if (n == 1)
      return 2;
    if (n == 2 && m == 1)
      return 3;
    if (n == 2)
      return 4;
    if (m == 1)
      return 4;
    if (m == 2)
      return 7;
    if (m >= 3)
      return 8;
    return 8;
  }
};

int main() {

  // int n = 1, m = 1;
  // int n = 2, m = 1;
  int n = 1000, m = 1000;
  Solution sln;
  printf("%d\n", sln.flipLights(n, m));  
  return 0;
}
