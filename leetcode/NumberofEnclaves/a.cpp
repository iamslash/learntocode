/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 52ms 89.82% 14.5MB 100.00%
// DFS
// O(N) O(1)
class Solution {
 private:
  void dfs(std::vector<std::vector<int>>& A, int y, int x) {
    int h = A.size(), w = A[0].size();
    // base
    if (y < 0 || y >= h || x < 0 || x >= w || A[y][x] == 0)
      return;
    A[y][x] = 0;
    dfs(A, y-1,   x);
    dfs(A,   y, x+1);
    dfs(A, y+1,   x);
    dfs(A,   y, x-1);    
  }
 public:
  int numEnclaves(std::vector<std::vector<int>>& A) {
    int h = A.size(), w = A[0].size(), ans = 0;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (y == 0 || y == h-1 || x == 0 || x == w-1)
          dfs(A, y, x);
      }
    }
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (A[y][x])
          ans++;
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
