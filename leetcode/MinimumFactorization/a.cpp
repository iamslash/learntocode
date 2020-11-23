/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <cmath>
#include <climits>

// 0ms 100.00% 8.5MB 100.00%
class Solution {
 public:
  int smallestFactorization(int q) {
    if (q < 2)
      return q;
    int64_t r = 0;
    // d is for 32-bit integer limit
    for (int i = 9, d = 0; i > 1 && d < 10; --i) {
      while (q % i == 0 && d < 10) {
        r += i * std::pow(10, d++);
        q /= i;
      }
    }
    return q > 1 || r > INT_MAX ? 0 : r;
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.smallestFactorization(48));
  printf("%d\n", sln.smallestFactorization(15));
  printf("%d\n", sln.smallestFactorization(13));
  
  return 0;
}
