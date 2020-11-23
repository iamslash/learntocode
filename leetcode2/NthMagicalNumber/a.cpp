/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cstdint>
#include <cmath>
#include <algorithm>

using namespace std;

// N: 1
// A: 2
// B: 3
//
// M: 2
//
//  A: 4
//  B: 6
// AA: 4 16
// BB:

// A: 4
// B: 6

// 0ms 100.00% 5.9MB 81.72%
// binary search
// O(lgN) O(1)
#define MOD 1000000007
class Solution {
 private:
  int gcd(int a, int b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }
 public:
  int nthMagicalNumber(int N, int A, int B) {
    int64_t lcm = A * B / __gcd(A, B);
    int64_t lo = 2, hi = 1e14;
    while (lo < hi) {
      int64_t mi = lo + (hi - lo) / 2;
      if (mi/A + mi/B - mi/lcm < N) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return lo % MOD;
  }
};
