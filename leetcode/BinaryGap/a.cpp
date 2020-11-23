/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>

//    r
// N: 10110
// c: 1

//       r
// N: 1000
// c: 0

// 0ms 100.00% 8.2MB 100.00%
// O(N) O(1)
class Solution {
 public:
  int binaryGap(int N) {
    int cnt = -1, ans = 0;
    while (N) {
      int quo = N / 2;
      int rem = N % 2;
      if (rem) {
        if (cnt > 0) {
          ans = std::max(ans, cnt);
        }
        cnt = 1;
      } else if (cnt >= 0) {
        cnt++;
      }
      N = quo;
    }
    return ans;
  }
};

int main() {
  return 0;
}
