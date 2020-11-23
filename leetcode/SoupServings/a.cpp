/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 0ms 100.00% 14.8MB 75.00%
// dynamic programming
// O(N^2) O(N)
class Solution {
 private:
  double dfs(
      std::unordered_map<int, std::unordered_map<int, double>>& C,
      int A, int B) {
    // base
    if (A <= 0 && B <= 0)
      return 0.5;
    if (A <= 0)
      return 1;
    if (B <= 0)
      return 0;

    // memo
    if (C.count(A) && C[A].count(B))
      return C[A][B];

    // recursion
    double& r = C[A][B];
    r = dfs(C, A-100, B) +
        dfs(C, A-75, B-25) +
        dfs(C, A-50, B-50) +
        dfs(C, A-25, B-75);
    r *= 0.25;
    return r;
  }
 public:
  double soupServings(int N) {
    if (N >= 4800)
      return 1.0;
    std::unordered_map<int, std::unordered_map<int, double>> C;
    return dfs(C, N, N);
  }
};

int main() {
  return 0;
}
