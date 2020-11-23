/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>

// N: 22 11 5 2 1
// r:  0  1 1 0 1

// N: 5 2 1
// r: 1 0 1

// 0ms 100.00% 8.1MB 100.00%
class Solution {
 public:
  int binaryGap(int N) {
    int ans = 0, cnt = -1;
    while (N > 0) {
      if (N % 2) {
        ans = std::max(ans, ++cnt);
        cnt = 0;
      } else {
        if (cnt >= 0)
          cnt++;
      }
      N /= 2;
    }
    return ans;
  }
};

int main() {
  return 0;
}
