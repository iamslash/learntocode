/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// n: 32
//    11
//    11
//    10

// 48ms 100.00% 13.9MB 25.00%
// greedy algorithm
// O(N) O(1)
class Solution {
 public:
  int minPartitions(string n) {
    int ans = 0;
    for (char c : n) {
      ans = max(ans, c-'0');
    }
    return ans;
  }
};
