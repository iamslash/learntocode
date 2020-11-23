/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <cmath>
//         e            u
// 1 2 ... 9 10 11 ... 99 100 101 ... 999 1000 1001 ... 9999
// 9 * 1 * 1   9 * 10 * 2     9 * 100 * 3       9 * 1000 * 4
//     d   i

// 0ms 100.00% 8.5MB 25.00%
// brute force
// O(N) O(1)
class Solution {
 public:
  int findNthDigit(int n) {
    int i = 1;
    int64_t e = 9;
    while (n > e * i) {
      n -= e * i;
      ++i;
      e *= 10;
    }
    int num = std::pow(10, i-1) + (n-1) / i;
    std::string s = std::to_string(num);
    return s[(n-1) % i] - '0';
  }
};

int main() {

  Solution sln;
  for (int i = 0; i < 50; ++i) 
    printf("%d\n", sln.findNthDigit(i));
  
  return 0;
}
