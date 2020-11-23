/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

const int MOD = 1e9+7;

// 4ms 100.00%
// O(4^N) O(N)
class Solution {
 private:
  std::vector<std::vector<std::vector<int64_t>>> m_C;
  std::vector<std::pair<int, int>> m_D = {{-1,0},{0,1},{1,0},{0,-1}};
  int m_h;
  int m_w;
  int64_t solve(int y, int x, int n) {
    // base
    if (y < 0 || y >= m_h || x < 0 || x >= m_w)
      return 1;
    if (n <= 0)
      return 0;
    // memoization
    int64_t& r = m_C[y][x][n];
    if (r != -1)
      return r;

    r = 0;
    // recursion
    for (int i = 0; i < 4; ++i) {
      int ny = y + m_D[i].first;
      int nx = x + m_D[i].second;
      r += solve(ny, nx, n-1) % MOD;
    }
    // printf("y: %d, x: %d, n: %d, r: %d\n", y, x, n, r);    
    return r % MOD;
  }
 public:
  int findPaths(int m, int n, int N, int i, int j) {
    if (N == 0)
      return 0;
    m_h = m;
    m_w = n;
    m_C.resize(
        m,
        std::vector<std::vector<int64_t>>(
            n,
            std::vector<int64_t>(N+1,-1)));
    return solve(i, j, N) % MOD;
  }
};

int main() {
  Solution sln;
  // printf("%d\n", sln.findPaths(1, 1, 1, 0, 0));
  // printf("%d\n", sln.findPaths(2, 2, 2, 0, 0));
  // printf("%d\n", sln.findPaths(1, 3, 3, 0, 1));
  printf("%d\n", sln.findPaths(8, 50, 23, 5, 26));
  return 0;
}
