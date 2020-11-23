/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/809/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

// wrong solution
// class Solution {
//  public:
//   std::vector<int> C; // cache
//   std::vector<int> V; // coins
//   int _solve(int amount, int i, int k = 0) {

//     // base condition
//     if (amount == 0)
//       return 0;
//     else if (amount < 0 || i >= V.size())
//       return std::numeric_limits<int>::max() - 1;

//     // for (int j = 0; j < k; ++j)
//     //   printf(" ");
//     // printf("a: %d i: %d\n", amount, i);    
    
//     // memoization
//     int& r = C[i];
//     if (r != -1)
//       return r;

//     // recursion
//     r = std::numeric_limits<int>::max() - 1;
//     r = std::min(1 + _solve(amount - V[i], i, k+1),
//                  _solve(amount, i+1, k+1));
//     // for (int j = 0; j < k; ++j)
//     //   printf(" ");
//     // printf("r: %d\n", r);    
//     return r;
//   }
//   int coinChange(std::vector<int>& coins, int amount) {
//     if (coins.empty())
//       return -1;
//     if (coins.size() == 1)
//       return coins[0] == amount ? 1 : -1;

//     // for upper 2 coins
//     C = std::vector<int>(coins.size(), -1);
//     V = coins;
//     int r = std::numeric_limits<int>::max() - 1;
//     r = std::min(1 + _solve(amount - V[0], 0),
//                  _solve(amount, 1));
//     return r >= std::numeric_limits<int>::max() - 1 ? -1 : r;
//   }
// };

// -1 -1 -1 -1 -1 -1 -1
//  5  1
class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    // C[i]: min coin count of i amount
    std::vector<int> C(amount+1, -1);
    C[0] = 0;
    for (int a : coins) {
      for (int b = a; b <= amount; ++b) {
        if (C[b - a] >= 0 && (C[b] < 0 || C[b-a]+1 < C[b])) {
          C[b] = C[b-a] + 1;
        }
      }
    }
    return C[amount];
  }
};

int main() {
  std::vector<int> v = {1, 2, 5};
  // std::vector<int> v = {5, 1};
  int a = 11;
  
  Solution s;
  printf("%d\n", s.coinChange(v, a));
  return 0;
}
