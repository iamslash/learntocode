/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

// p: s+1
// p
// 1 17 8 1
// i

// 0ms 100.00% 9MB 23.69%
// O(N!) O(N)
class Solution {
 private:
  int dfs(std::vector<int>& A, int s) {
    int n = A.size();

    // base
    if (s+1 == n)
      return 1;

    // recursion
    int ans = 0;
    std::unordered_set<int> ust;
    for (int i = s+1; i < n; ++i) {
      // A[s], A[i] are adjacent numbers
      if (!ust.insert(A[i]).second)
        continue;
      if (s == -1 || std::pow((int)sqrt(A[i] + A[s]), 2) == A[i] + A[s]) {
        std::swap(A[i], A[s+1]);
        ans += dfs(A, s+1);
        std::swap(A[i], A[s+1]);
      }
    }
    return ans;
  }
 public:
  int numSquarefulPerms(std::vector<int>& A) {
    return dfs(A, -1);
  }
};

int main() {
  return 0;
}
