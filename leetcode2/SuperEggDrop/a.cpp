/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 0ms 100.00% 6.1MB 92.31%
// iterative dynamic programming
// O(KN) O(K)
class Solution {
 public:
  int superEggDrop(int K, int N) {
    vector<int> C(K+1);
    int ans = 0;
    while (C[K] < N) {
      for (int i = K; i > 0; --i) {
        C[i] = 1 + C[i] + C[i-1];
      }
      ans++;
    }
    return ans;
  }
};
