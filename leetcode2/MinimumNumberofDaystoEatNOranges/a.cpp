/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>

using namespace std;

// 20ms 65.45% 9.7MB 81.11%
class Solution {
 private:
  unordered_map<int, int> C;
 public:
  int minDays(int n) {
    // base
    if (n <= 1)
      return n;
    if (C.count(n) == 0)
      C[n] = 1 + min(n%2 + minDays(n/2), n%3 + minDays(n/3));
    return C[n];
  }
};
