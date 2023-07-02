/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 145ms 35.51% 14.4MB 83.32%
// iterative dynamic programming
// O(AN) O(N)
// A: amount
// N: number of coins
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> C(amount + 1, amount + 1);
    C[0] = 0;
    for (int a = 0; a <= amount; ++a) {
      for (int i = 0; i < n; ++i) {
        if (coins[i] <= a) {
          C[a] = min(C[a], 1 + C[a - coins[i]]);
        }
      }
    }
    if (C[amount] == amount + 1) {
      return -1;
    }
    return C[amount];    
  }
};
