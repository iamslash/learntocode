/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/rotate-image/description/

#include <cstdio>
#include <vector>
#include <algorithm>

// 1 2 3
// 4 5 6
// 7 8 9
class Solution {
 public:
  void rotate(int& a, int& b, int& c, int& d) {
    int t = a;
    a = b;
    b = c;
    c = d;
    d = t;
  }
  void rotate(std::vector<std::vector<int>>& M) {
    int n = M.size();
    if (n == 0)
      return;
    int t = M[n-1][0];
    for (int i = 0; i < n/2; ++i) {
      for (int j = 0; j < (n+1)/2; ++j) {
        // rotate(M[i][j], M[j][n-1-i], M[n-1-i][n-1-j], M[n-1-j][i]);
        rotate(M[i][j], M[n-1-j][i], M[n-1-i][n-1-j], M[j][n-1-i]);
      }
    }
  }
};

void printm(const std::vector<std::vector<int>>& M) {
  for (auto r : M) {
    for (auto rr : r) {
      printf("%d ", rr);
    }
    printf("\n");
  }
}

int main() {
  std::vector<std::vector<int>> M = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };

  printm(M);
  printf("\n");
  
  Solution s;
  s.rotate(M);

  printm(M);
  
  return 0;
}
