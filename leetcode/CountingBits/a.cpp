/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>


// 1100
// 0110
class Solution {
 public:
  std::vector<int> countBits(int n) {
    std::vector<int> rslt(n+1, 0);
    for (int i = 1; i <= n; ++i) {
      rslt[i] = rslt[i >> 1];
      if (i & 1)
        rslt[i]++;
    }
    return rslt;
  }
};

int main() {

  Solution sln;
  auto rslt = sln.countBits(8);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  return 0;
}
