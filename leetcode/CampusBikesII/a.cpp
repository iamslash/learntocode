/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 0ms 100.00% 11.3MB 50.00%
// DFS with dynamic programming
// O(WB) O(W)
class Solution {
 private:
  std::vector<std::vector<int>> m_C =
      std::vector<std::vector<int>>(
          10, std::vector<int>(1024, -1));
  int dfs(std::vector<std::vector<int>> &W,
          std::vector<std::vector<int>> &B,
          int i, int bused) {
    int m = W.size(), n = B.size();
      //printf("m:%d, n:%d, i:%d, bused:%d\n", m, n, i, bused);

    // base
    if (i >= m)
      return 0;

    // memo
    int &r = m_C[i][bused];
    if (r >= 0)
      return r;
    r = INT_MAX;

    // recursion
    for (int j = 0; j < n; ++j) {
      int bm = 1 << j;
      if (bused & bm)
        continue;
      int dist = std::abs(W[i][0]-B[j][0]) +
          std::abs(W[i][1]-B[j][1]);
      dist += dfs(W, B, i+1, bused | bm);
      r = std::min(r, dist);
    }

    return r;
  }
 public:
  int assignBikes(std::vector<std::vector<int>> &W,
                  std::vector<std::vector<int>> &B) {
    return dfs(W, B, 0, 0);
  }
};

int main() {
  return 0;
}
