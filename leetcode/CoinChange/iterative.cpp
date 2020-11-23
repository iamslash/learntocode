/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// amout: 11
//        i
// coins: 1 2 5
//          a
//     C: 0 M M M M M M M M M M M M
//        .         .         . 

// 100ms 65.09% 14.2MB 5.20%
// iterative dynamic programming
// O(AC) O(A)
#define MAX_VAL 10000
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size();
      vector<int> C(amount+1, MAX_VAL);
      C[0] = 0;
      for (int a = 0; a <= amount; a++) {
        for (int i = 0; i < n; ++i) {
          if (coins[i] <= a) {
            C[a] = min(C[a], C[a-coins[i]] + 1);
          }
        }
      }
      return C[amount] >= MAX_VAL ? -1 : C[amount];
    }
};
