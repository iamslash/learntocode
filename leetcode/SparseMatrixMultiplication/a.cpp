/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// 12ms 100.00% 9.6MB 100.00%
// O(YXW) O(1)
class Solution {
 public:
  std::vector<std::vector<int>> multiply(
      std::vector<std::vector<int>>& A,
      std::vector<std::vector<int>>& B) {
    if (A.empty() || A[0].empty() || B.empty() || B[0].empty())
      return {};
    std::vector<std::vector<int>> rslt(
        A.size(), std::vector<int>(B[0].size(), 0));
    for (int y = 0; y < A.size(); ++y) {
      for (int w = 0; w < B[0].size(); ++w) {
        int val = 0;
        for (int x = 0; x < A[0].size(); ++x) {
          if (A[y][x] != 0 && B[x][w] != 0) {
            val += A[y][x] * B[x][w];
          }
        }
        rslt[y][w] = val;
      }
    }
    return rslt;
  }
};

int main() {

  // std::vector<std::vector<int>> A = {
  //   {1, 0, 0},
  //   {-1, 0, 3}
  // };
  // std::vector<std::vector<int>> B = {
  //   {7, 0, 0},
  //   {0, 0, 0},
  //   {0, 0, 1}
  // };
  std::vector<std::vector<int>> A = {
    {1, -5},
  };
  std::vector<std::vector<int>> B = {
    {12},
    {-1}
  };

  Solution sln;
  auto V = sln.multiply(A, B);
  for (auto& l : V) {
    for (int a : l)
      printf("%d ", a);
    printf("\n");
  }

  return 0;
}
