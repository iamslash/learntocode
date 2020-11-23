/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// 1 2 3 4 5 6 7 8 9 10
// 11 12 13 14 15 16 17 18 19 20
// 21 22 23 24 25 26 27 28 29 30
// ...
// 91 92 93 94 95 96 97 98 99 100
// 101 102 103 104
// 111
// 121
// 131
// ...
// 191 192 193
// 201 202 203
// 211
// 212
// ...
// 291 292 293
// 301

// converting 10 base int to 9 base int
// 4ms 100.00% 8.1MB 100.00%
// O(log9N) O(1)
class Solution {
 public:
  int newInteger(int n) {
    if (n <= 8)
      return n;
    return 10*newInteger(n/9) + (n%9);
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.newInteger(9));
  return 0;
}
