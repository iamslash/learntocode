/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

// 1 2 3
// 4 5 6
// 7 8 9
//   0

// 52ms 79.44% 8.4MB 79.71%
// dynamic programming
# define MOD 1000000007
class Solution {
 public:
  int knightDialer(int N) {
    std::vector<std::vector<int>> moves = {
      {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0},
      {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}
    };
    std::vector<int> C0(10, 1), C1(10, 0);
    while (--N > 0) {
      for (int i = 0; i < 10; ++i) {
        C1[i] = std::accumulate(moves[i].begin(),
                                moves[i].end(),
                                0,
                                [&](int s, int a) {
                                  return (s + C0[a]) % MOD;
                                });
      }
      std::swap(C0, C1);
    }
    return std::accumulate(C0.begin(),
                           C0.end(), 0,
                           [](int s, int a) {
                             return (s + a) % MOD;
                           });
  }
};

int main() {

  Solution sln;

  printf("%d\n", sln.knightDialer(4));
  
  return 0;
}
