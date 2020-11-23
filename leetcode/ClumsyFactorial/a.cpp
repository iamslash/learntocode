/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// 4ms 75.89% 8.2MB 69.23%
// brute force
// O(N) O(1)
class Solution {
 public:
  int clumsy(int N) {
    int ans = 0;
    int tmp = 0;
    while (N > 0) {
      if (N > 0) {
        tmp = tmp == 0 ? N : -N;
        N--;
      }
      if (N > 0)
        tmp *= N--;
      if (N > 0)
        tmp /= N--;
      if (N > 0)
        tmp += N--;
      ans += tmp;
    }
    return ans;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.clumsy(4));
  printf("%d\n", sln.clumsy(10));
  
  return 0;
}
