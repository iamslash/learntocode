/* Copyright (C) 2020 by iamslash */

#include <cstdio>

using namespace std;

// brute force
// 0ms 100.00% 6.2MB 100.00%
class Solution {
 public:
  int numberOfMatches(int n) {
    int ans = 0;
    while (n > 1) {
      int team = 0;
      if (n % 2 == 0) {
        team = n/2;
        n = team;
      } else {
        team = (n-1)/2;
        n = team + 1;
      }
      ans += team;
    }
    return ans;
  }
};
