/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

// 12, 7
// 7 5
// 5 2
// 2 1
// 1 0

// 112ms 82.48% 29.3MB 60.87%
// bezout's identity
// O(N) O(1)
class Solution {
 private:
  int gcd(int a, int b) {
    if (b == 0)
      return a;
    return gcd(b, a%b);
  }
 public:
  bool isGoodArray(vector<int>& A) {
    int g = A[0];
    for (int a : A)
      g = gcd(g, a);
    return g == 1;
  }
};
