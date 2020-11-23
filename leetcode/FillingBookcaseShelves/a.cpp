/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // 40ms 5.47% 123.8MB 100.00%
// // dynamic programming
// // O(N^2) O(N)
// class Solution {
//  private:
//   int dfs(std::vector<std::vector<int>>& B,
//           int W, std::vector<std::vector<int>>& C,
//           int i, int w, int h) {
//     int n = B.size();
//     // base
//     if (i >= n)
//       return h;

//     // memo
//     int& r = C[i][w];
//     if (r != -1)
//       return r;

//     // recursion
//     int nextshef = h + dfs(B, W, C, i+1, B[i][0], B[i][1]);
//     int thisshef = INT_MAX;
//     if (w + B[i][0] <= W)
//       thisshef = dfs(B, W, C, i+1, w + B[i][0], std::max(h, B[i][1]));
//     r = std::min(thisshef, nextshef);
//     return r;
//   }
//  public:
//   int minHeightShelves(
//       std::vector<std::vector<int>>& B, int W) {
//     int n = B.size(), ans = INT_MAX;
//     std::vector<std::vector<int>> C(1001, std::vector<int>(1001, -1));
//     return dfs(B, W, C, 0, 0, 0);
//   }
// };

// 8ms 62.87% 9.7MB 100.00%
// dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int minHeightShelves(std::vector<std::vector<int>>& B, int W) {
    int n = B.size();
    std::vector<int> C(n+1, 0);
    for (int i = 1; i <= n; ++i) {
      int w = B[i-1][0];
      int h = B[i-1][1];
      C[i] = C[i-1] + h;
      for (int j = i-1; j > 0 && w + B[j-1][0] <= W; --j) {
        h = std::max(h, B[j-1][1]);
        w = w + B[j-1][0];
        C[i] = std::min(C[i], C[j-1] + h);
      }
    }
    return C[n];
  }
};

int main() {
  return 0;
}
