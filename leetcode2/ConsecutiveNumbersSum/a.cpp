/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cmath>

using namespace std;

// 4ms 84.64% 6MB 46.56%
// math
// O(N) O(1)
class Solution {
 public:
  int consecutiveNumbersSum(int N) {
    int cnt = 1;
    for (int k = 2; k < sqrt(2*N); ++k) {
      if ((N-(k*(k-1)/2)) % k == 0)
        cnt++;
    }
    return cnt;
  }
};
