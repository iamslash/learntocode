/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 00 -> 10
// 10 -> 01

// zero moves to left to meet another zero
// 010  -> 001 -> 101
// 0110 -> 0101 -> 0011 -> 1011
// 01110 -> 01101 -> 01011 0> 00111 -> 10111

//            i
//    s: 10111
// oCnt: 0
// zCnt: 2

// 200ms 58.46% 40.7MB 88.46%
// greedy algorithm
// O(N) O(1)
class Solution {
 public:
  string maximumBinaryString(string s) {
    int oneCnt = 0, zeroCnt = 0, n = s.size();
    for (auto& c : s) {
      if (c == '0') {
        zeroCnt++;
      } else if (zeroCnt == 0) {
        oneCnt++;
      }
      c = '1';
    }
    if (oneCnt < n) {
      s[oneCnt + zeroCnt - 1] = '0';
    }
    return s;
  }
};
