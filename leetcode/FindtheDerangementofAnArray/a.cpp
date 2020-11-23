/* Copyright (C) 2019 by iamslash */

// 1 : 0
// 1 2 : 1
// 1 2 3 : 2
// 1 2 3 4 : 6 
// 1 2 3 4 5 : 24 

#include <cstdio>

// 12ms 75.38% 8.3MB 100.00%
#define MOD 1000000007
class Solution {
 public:
  int findDerangement(int n) {
    int64_t rslt = 1;
    for (int i = 1; i <= n; ++i)
      rslt = (i * rslt % MOD + (i & 1 ? -1 : 1)) % MOD;
    return (int)rslt;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.findDerangement(3));
  printf("%d\n", sln.findDerangement(4));
  printf("%d\n", sln.findDerangement(5));
  printf("%d\n", sln.findDerangement(1000000));
  
  return 0;
}
