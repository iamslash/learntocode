// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/divide-two-integers/description/

#include <cstdio>
#include <vector>
#include <limits>
#include <cmath>
#include <cstdint>

// 12ms 97.80%
// O(lgN) O(1)
class Solution {
 public:
  int divide(int a, int b) {
    if (b == 1)
      return a;
    if (b == -1 && a == std::numeric_limits<int>::min())
      return std::numeric_limits<int>::max();
    
    int rr = 0;
    bool bneg = (a < 0) ^ (b < 0);
    int64_t aa = a;
    int64_t bb = b;
    aa = aa < 0 ? -aa : aa;
    bb = bb < 0 ? -bb : bb;
    // printf("%lld %lld\n", aa, bb);

    // 
    while (aa >= bb) {
      int64_t c = bb;
      int64_t q = 1;
      while (aa >= c) {
        aa -= c;
        rr += q;
        c <<= 1;
        q <<= 1;
        
        // printf("a:%ld c:%ld q:%ld rr:%d\n", aa, c, q, rr);
      }
    }
    
    return bneg ? -rr : rr;
  }
};

int main() {
  // int a = 10, b = 3;
  // int a = 7, b = -3;
  // int a = 1, b = 1;
  // int a = -2147483648, b = -1;
  // int a = 1004958205, b = -2137325331;
  // int a = -2147483648, b = 1;
  // int a = 2147483647, b = 2;
  int a = -2147483648, b = 2;
  
  Solution s;
  printf("%d\n", s.divide(a, b));
  return 0;
}
