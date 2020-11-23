/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// 4ms 55.56% 8.2MB 100.00%
// geometry
// O(lg(min(p, q))) O(1)
class Solution {
 public:
  int mirrorReflection(int p, int q) {
    while (p % 2 == 0 && q % 2 == 0)
      p /= 2, q /= 2;
    if (p % 2 == 0)
      return 2;
    else if (q % 2 == 0)
      return 0;
    return 1;
  }
};

int main() {
  return 0;
}
