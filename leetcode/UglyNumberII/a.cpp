/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 8ms 85.06% 7.7MB 5.29%
// iterative dyanamic programming
// O(N) O(N)
class Solution {
 public:
  int nthUglyNumber(int n) {
    int i2 = 0, i3 = 0, i5 = 0;
    vector<int> C(n+1);
    C[0] = 1;
    for (int i = 1; i < n; ++i) {
      int n2 = C[i2] * 2;
      int n3 = C[i3] * 3;
      int n5 = C[i5] * 5;
      C[i] = min(n2, min(n3, n5));
      if (C[i] == n2)
        i2++;
      if (C[i] == n3)
        i3++;
      if (C[i] == n5)
        i5++;
    }
    return C[n-1];
  }
};
