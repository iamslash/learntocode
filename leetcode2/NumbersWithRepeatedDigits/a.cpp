/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cstdint>

using namespace std;

// 1472ms 6.04% 5.9MB 95.97%
// DFS
// O(10^N) O(N)
class Solution {
 private:
  int uniqDigits;
  void dfs(int64_t cur, int bm, int N) {
    // base
    if (cur > N)
      return;    
    // recursion
    uniqDigits++;
    for (int digit = 0; digit < 10; digit++) {
      if (bm == 0 && digit == 0)
        continue;
      if ((bm & (1 << digit)) > 0)
        continue;
      dfs(cur * 10 + digit, bm | (1 << digit), N);
    }
  }
 public:
  int numDupDigitsAtMostN(int N) {
    dfs(0, 0, N);
    return N - uniqDigits + 1;
  }
};

