/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 2 4 5 10 20
// 1 2 1  3  9

// 16ms 40.73% 10MB 51.45%
// O(N^2) O(N)
#define MOD 1000000007;
class Solution {
 public:
  int numFactoredBinaryTrees(std::vector<int>& A) {
    int n = A.size();
    std::sort(A.begin(), A.end());
    std::unordered_map<int, int64_t> C;
    for (int i = 0; i < n; ++i) {
      C[A[i]] = 1;
      for (int j = 0; j < i; ++j) {
        if (A[i] % A[j] == 0 &&
            C.count(A[i] / A[j]))
          C[A[i]] = (C[A[i]] + C[A[j]] * C[A[i]/A[j]]) % MOD;
      }
    }
    int r = 0;
    for (auto& pr : C)
      r = (r + pr.second) % MOD;
    return r;
  }
};

int main() {
  return 0;
}
