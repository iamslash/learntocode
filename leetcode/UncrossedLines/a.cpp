/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 16ms 44.50% 11.9MB 60.82%
// dynamic programming
// O(HW) O(W)
class Solution {
 public:
  int maxUncrossedLines(std::vector<int>& A, std::vector<int>& B) {
    int h = A.size(), w = B.size();
    std::vector<std::vector<int>> C(
        h+1, std::vector<int>(w+1, 0));
    for (int y = 1; y <= h; ++y) {
      for (int x = 1; x <= w; ++x) {
        int d = A[y-1] == B[x-1] ? 1 : 0;
        C[y][x] = std::max(
            C[y][x-1],
            std::max(C[y-1][x], C[y-1][x-1] + d));
      }
    }
    return C[h][w];
  }
};

int main() {

  std::vector<int> A = {1, 4, 2};
  std::vector<int> B = {1, 2, 4};

  Solution sln;

  printf("%d\n", sln.maxUncrossedLines(A, B));
  
  return 0;
}
