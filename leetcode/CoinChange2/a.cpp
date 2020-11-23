/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// //            i
// // coins: 1 2 5
// //     j: 1
// //     C: 1 1 2 1 3 2
// // 8ms 57.18%
// // dynamic programming iterative way
// // O(N^2) O(N)
// class Solution {
//  public:
//   int change(int amount, std::vector<int>& coins) {
//     if (amount == 0)
//       return 1;
//     if (coins.size() == 0)
//       return 0;
//     // C[i] : count for i amount
//     std::vector<int> C(amount + 1, 0);
//     C[0] = 1;
//     // i : index of coin, j: value of coins[i]
//     for (int i = 0; i < coins.size(); ++i) {
//       for (int j = coins[i]; j <= amount; ++j) {
//         C[j] += C[j - coins[i]];
//       }
//     }
//     return C[amount];
//   }
// };

// 4ms 100.00%
// dynamic programming iterative way
// O(N^2) O(N)
class Solution {
 public:
  int change(int amount, const std::vector<int>& coins) {
    std::vector<int> C(amount + 1, 0);
    C[0] = 1;
    for (int c : coins) {
      for (int i = 0; i + c <= amount; ++i) {
        C[i + c] += C[i];
      }
    }
    return C[amount];
  }
};

int main() {

  std::vector<int> coins = {1, 2, 5};
  int A = 5;
  Solution sln;
  printf("%d\n", sln.change(A, coins));
  
  return 0;
}
