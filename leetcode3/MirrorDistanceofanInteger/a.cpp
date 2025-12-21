/* Copyright (C) 2025 by iamslash */

#include <cstdio>
#include <cmath>

// 0ms 100.00% 8.6MB 36.36%
// math
// O(N) O(1)
class Solution {
public:
  int mirrorDistance(int n) {
    int org_num = n;
    int rev_num = 0;

    while (n > 0) {
      int digit = n % 10;
      n /= 10;

      rev_num = rev_num * 10 + digit;
    }

    return abs(org_num - rev_num);
  }
};

int main() {
  return 0;
}
