/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// 7 5
// 5 2
// 2 1
// 1 0

// 0ms 100.00% 8.2MB 100.00%
// binary search
// O(lgN) O(1)
class Solution {
 private:
  long gcd(long a, long b) {
    if (b == 0)
      return a;
    return gcd(b, a%b);
  }
 public:
  int nthUglyNumber(int n, int A, int B, int C) {
    int lo = 1, mi = 0, hi = 2 * (int) 1e9;
    long a = long(A), b = long(B), c = long(C);
    long ab = a * b / gcd(a, b);
    long bc = b * c / gcd(b, c);
    long ac = a * c / gcd(a, c);
    long abc = a * bc / gcd(a, bc);
    while (lo < hi) {
      mi = lo + (hi - lo) / 2;
      int cnt = mi/a + mi/b + mi/c - mi/ab - mi/bc - mi/ac + mi/abc;
      if (cnt < n) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return lo;
  }
};

int main() {
  return 0;
}
