/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0

//
// 3 1 5 8
// 8ms 58.90%
class Solution {
 public:
  int maxCoins(std::vector<int>& V) {
    int n = V.size();
    V.insert(V.begin(), 1);
    V.insert(V.end(), 1);
    // C[i][j] = best coins between i and j
    std::vector<std::vector<int>> C(
        V.size(),
        std::vector<int>(V.size(), 0));
    for (int len = 1; len <= n; ++len) {
      for (int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;
        for (int k = i; k <= j; ++k) {
          C[i][j] = std::max(
              C[i][j],
              C[i][k-1] + C[k+1][j] + V[i-1] * V[k] * V[j+1]);
        }
      }
    }
    return C[1][n];
  }
};

int main() {
  std::vector<int> V = {3, 1, 5, 8};
  Solution sln;
  printf("%d\n", sln.maxCoins(V));
  return 0;
}
