/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 48ms 75.51% 11.8MB 48.90%
// O(N^N) O(N)
class Solution {
 public:
  int largestOverlap(std::vector<std::vector<int>>& A,
                     std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<int> C;
    std::vector<int> D;
    std::unordered_map<int, int> cnts;
    for (int i = 0; i < n*n; ++i) {
      if (A[i/n][i%n])
        C.push_back(i / n * 100 + i % n);
    }
    for (int i = 0; i < n*n; ++i) {
      if (B[i/n][i%n])
        D.push_back(i / n * 100 + i % n);
    }
    for (int a : C) {
      for (int b : D) {
        cnts[a - b]++;
      }
    }
    int r = 0;
    for (auto& pr : cnts)
      r = std::max(r, pr.second);
    return r;
  }
};

int main() {
  return 0;
}
