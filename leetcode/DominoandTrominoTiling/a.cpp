/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// 4ms 88.19% 8.3MB 86.72%
// dynamic programming
// O(N) O(1)
#define MOD 1000000007
class Solution {
 public:
  int numTilings(int N) {
    // C[n] = 2 * C[n-1] + C[n-3]
    int64_t C[4] = {1,1,2,5};
    if (N < 4)
      return C[N];
    for (int i = 4; i <= N; ++i) {
      int tmp = (2 * (C[3] % MOD) + (C[1] % MOD)) % MOD;
      C[0] = C[1];
      C[1] = C[2];
      C[2] = C[3];
      C[3] = tmp;
    }
    return C[3] % MOD;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.numTilings(1));
  printf("%d\n", sln.numTilings(2));
  printf("%d\n", sln.numTilings(3));
  printf("%d\n", sln.numTilings(4));
  printf("%d\n", sln.numTilings(5));
  printf("%d\n", sln.numTilings(6));
  
  return 0;
}
