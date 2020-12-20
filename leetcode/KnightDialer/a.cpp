/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// 164ms 67.34% 6.5MB 92.71%
// iterative dynamic programming
// O(N) O(1)
#define MOD 1000000007
class Solution {
public:
    int knightDialer(int n) {
      vector<vector<int>> moves = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4},
      };
      vector<int> C0(10, 1), C1(10, 0);
      while (--n > 0) {
        for (int i = 0; i < 10; ++i) {
          C1[i] = 0;
          for (int key : moves[i]) {
            C1[i] = (C1[i] + C0[key]) % MOD;
          }
        }
        swap(C0, C1);
      }
      int sum = 0;
      for (int i = 0; i < 10; ++i) {
        sum = (sum + C0[i]) % MOD;
      }
      return sum;
    }
};
