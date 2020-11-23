/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cstdint>

using namespace std;

//  d: 1
// lo: 1
// hi: 13

// 0ms 100.00% 6.1MB 32.00%
class Solution {
 public:
  int digitsCount( int d, int lo, int hi ) {
    if( d < 0 || hi < 0 ) {
      return 0;
    }
    return countDigit(d, hi) - countDigit(d, lo - 1);
  }
    
 private:
  int countDigit(int digit, int value) {
    int count = 0;
    for( int pow10 = 1; pow10 <= value; pow10 *= 10 ) {
      int divisor = pow10 * 10;
            
      int quotient = value / divisor;
      if( quotient > 0 ) {
        count += quotient * pow10;                
      }

      if( digit == 0 ) {
        count -= pow10;
      }
            
      int remainder = value % divisor;
      if( remainder >= digit * pow10 ) {
        count += std::min(remainder - digit * pow10 + 1, pow10 );
      }
    }
    return count;
  }
};
