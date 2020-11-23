/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 76ms 94.08% 10.4MB 46.92%
// dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int lenLongestFibSubseq(std::vector<int>& A) {
    int ans = 0, n = A.size();
    std::unordered_map<int, int> idx;
    for (int i = 0; i < n; ++i)
      idx[A[i]] = i;
    std::unordered_map<int, int> maxlen;
    for (int k = 0; k < n; ++k) {
      for (int j = 0; j < k; ++j) {
        int fa = A[k] - A[j];
        if (fa < A[j] && idx.count(fa)) {
          int i = idx[fa];
          maxlen[j * n + k] = maxlen[i * n + j] + 1;
          ans = std::max(ans, maxlen[j * n + k] + 2);
        }
      }
    }
    return ans >= 3 ? ans : 0;
  }
};

int main() {
  return 0;
}
