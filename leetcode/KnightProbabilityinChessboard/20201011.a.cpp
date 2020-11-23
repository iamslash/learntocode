/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 16ms 71.95%
// O(KN^2) O(KN^2)
class Solution {
 private:
  int m_N;
  std::vector<std::vector<std::vector<double>>> m_C;
  double solve(int k, int y, int x) {
    // base
    if (k == 0) {
      return 1;
    }
    // memo
    double& r = m_C[k][y][x];
    if (r > 0.0)
      return r;      

    // recursion
    r = 0.0;
    int dy[8] = {-2, -1, 1, 2, 2,  1, -1, -2};
    int dx[8] = { 1,  2, 2, 1, -1,-2, -2, -1};
    for (int i = 0; i < 8; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= m_N || nx < 0 || nx >= m_N)
        continue;
      r += solve(k-1, ny, nx);
    }
    r /= 8.0;
    return r;
  }
 public:
  double knightProbability(int N, int K, int r, int c) {
    m_N = N;
    m_C = std::vector<std::vector<std::vector<double>>>(
        K+1, std::vector<std::vector<double>>(
            N, std::vector<double>(N, -1.0)));
    return solve(K, r, c);                                                        
  }
};

int main() {
  Solution sln;
  printf("%0.4lf\n", sln.knightProbability(3, 2, 0, 0));  
  return 0;
}
