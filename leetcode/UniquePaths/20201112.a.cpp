/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/808/

#include <cstdio>

class Solution {
public:
  int C[100][100];
  int m;
  int n;
  int _solve(int y, int x) {
    // base condition
    if (y == m-1 && x == n-1)
      return 1;
    else if (y >= m || x >= n)
      return 0;

    // memoization
    int& r = C[y][x];
    if (r >= 0)
      return r;

    // recursion
    return r = _solve(y+1, x) + _solve(y, x+1);
  }
  int uniquePaths(int a, int b) {
    m = a;
    n = b;
    for (int y = 0; y < a; ++y)
      for (int x = 0; x < b; ++x)
        C[y][x] = -1;
    return _solve(0, 0);
  }
};

int main() {
  // int m = 3, n = 2;
  int m = 7, n = 3;
  
  Solution s;
  printf("%d\n", s.uniquePaths(m, n));  
  return 0;
}
