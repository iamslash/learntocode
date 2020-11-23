/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 0ms 100.00% 8.3MB 43.86%
// brute force
// O(lgN) O(1)
class Solution {
 public:
  std::string baseNeg2(int N) {
    std::string ans;
    while (N) {
      int rem = std::abs(N % -2);
      N = (N - rem) / (-2);
      ans = (rem ? '1' : '0') + ans;
    }
    return ans.empty() ? "0" : ans;
  }
};

int main() {
  return 0;
}
