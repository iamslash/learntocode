/* Copyright (C) 2020 by iamslash */

#include <cstdio>

using namespace std;

// ans:  0 11 10  
//   n: 11 01  0

// ans:   0 110 101 100 
//   n: 110 010 001   0

// 0ms 100.00% 6.1MB 5.08%
// gray code
// O(lgN) O(1)
class Solution {
 public:
  int minimumOneBitOperations(int n) {
    int ans = 0;
    while (n > 0) {
      ans ^= n;
      n = n >> 1;
    }
    return ans;
  }
};
