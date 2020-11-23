/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cmath>

using namespace std;

// 4ms 23.70% 6.2MB 44.44%
// math
class Solution {
 public:
  int poorPigs(int n, int m, int p) {
    int x = 0;
    while (pow(p/m+1, x) < n) {
      x++;
    }
    return x;
  }
};
