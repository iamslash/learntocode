/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

// http://mathworld.wolfram.com/LagrangesFour-SquareTheorem.html
// Based on Lagrange's Four Square theorem, there 
// are only 4 possible results: 1, 2, 3, 4.
// 4ms 98.03%
class Solution {
 public:
  int is_square(int n){  
    int t = (int)std::sqrt(n);  
    return t * t == n;  
  }  
  int numSquares(int n) {
    // it's natural
    if (is_square(n))
      return 1;

    // return 4 if and only if n can be written in the
    // form of 4^k * (8 * m + 7)
    while ((n & 3) == 0) // n % 4 == 0
      n >>= 2;
    if ((n & 7) == 7) // n % 8 == 7
      return 4;

    // printf("-- %d\n", n);
    
    // return 3, if consists of 2 perfect squares
    int nn = (int)std::sqrt(n);
    for (int i = 1; i <= nn; ++i)
      if (is_square(n - i*i))
        return 2;

    // else 3
    return 3;
  }  
};
