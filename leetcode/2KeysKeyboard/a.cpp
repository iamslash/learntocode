/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <queue>

// 1
// 0
//
// 2
// 2
//
// 3
// 3
//
// 4
// 2 + m(2)

// 4ms 100.00% 8.9MB 100.00%
// O(NlgN) O(NlgN)
class Solution {
 public:
  int minSteps(int n) {
    if (n == 1)
      return 0;
    for (int i = 2; i < n; ++i)
      if (n % i == 0)
        return i + minSteps(n / i);
    return n;      
  }
};
 
int main() {

  Solution sln;
  printf("%d\n", sln.minSteps(29));
  
  return 0;
}
