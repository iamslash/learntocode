/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 40ms 82.63% 12.4MB 97.48%
// DFS paint and BFS find 1
// O(N^2) O(N)
class Solution {
 private:
  int paint(std::vector<std::vector<int>>& A, int y, int x) {
    if (y < 0 || x < 0 || y >= A.size() || x >= A.size() || A[y][x] != 1)
      return 0;
    A[y][x] = 2;
    return 1 +
        paint(A, y-1, x) +
        paint(A, y,   x+1) +
        paint(A, y+1, x) +
        paint(A, y,   x-1);
  }
  bool expand(std::vector<std::vector<int>>& A, int y, int x, int c) {
    if (y < 0 || x < 0 || y >= A.size() || x >= A.size())
      return false;
    if (A[y][x] == 0)
      A[y][x] = c + 1;
    return A[y][x] == 1;
  }
 public:
  int shortestBridge(std::vector<std::vector<int>>& A) {
    // paint with 2
    int n = A.size(), found = 0;
    for (int y = 0; !found && y < n; ++y) {
      for (int x = 0; !found && x < n; ++x) {
        found = paint(A, y, x);
      }
    }
    // search 1 with c + 1
    for (int c = 2; ; ++c) {
      for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
          if (A[y][x] != c)
            continue;
          if (expand(A, y-1, x, c) ||
              expand(A, y, x+1, c) ||
              expand(A, y+1, x, c) ||
              expand(A, y, x-1, c))
            return c - 2;
        }
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
