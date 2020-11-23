/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 4ms 88.37% 8.3MB 100.00%
// cycle detection
// O(N) O(N)
class Solution {
 public:
  std::vector<int> prisonAfterNDays(
      std::vector<int>& C, int N) {
    int cycle = 0, n = C.size();;
    std::vector<int> firstC, nextC(n, 0);
    while (N-- > 0) {
      for (int i = 1; i < n - 1; ++i)
        nextC[i] = C[i-1] == C[i+1];
      if (cycle == 0)
        firstC = nextC;
      else if (nextC == firstC)
        N %= cycle;
      C = nextC;
      ++cycle;
    }    
    return C;        
  }
};

int main() {
  return 0;
}
