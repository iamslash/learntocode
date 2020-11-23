/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
// 4ms 97.10%
class Solution {
 public:
  int nthUglyNumber(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    // make ugly numbers using 2, 3, 5 multiply
    std::vector<int> v(n, 1);
    int i2 = 0, i3 = 0, i5 = 0; // last index of numbers to multiply 2, 3, 5
    int n2 = 0, n3 = 0, n5 = 0; // numbers multiplied by 2, 3, 5
    for (int i = 1; i < n; ++i) {
      n2 = v[i2]*2;
      n3 = v[i3]*3;
      n5 = v[i5]*5;
      v[i] = std::min(n2, std::min(n3, n5));
      if (v[i] == n2) i2++;
      if (v[i] == n3) i3++;
      if (v[i] == n5) i5++;
      // printf("%2d %d\n", i, v[i]);
    }    
    return v[n-1];
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.nthUglyNumber(10));
  return 0;
}
