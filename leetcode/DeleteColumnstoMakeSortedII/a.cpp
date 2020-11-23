/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>

// 16ms 19.85% 9.5MB 100.00%
// greedy
// O(MN) O(N)
class Solution {
 public:
  int minDeletionSize(std::vector<std::string>& A) {
    std::unordered_set<char> D;
    int n = A.size();
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < A[i].size(); ++j) {
        if (D.count(j) || A[i-1][j] == A[i][j])
          continue;
        if (A[i-1][j] > A[i][j]) {
          D.insert(j);
          i = 0;
        }
        break;
      }
    }
    return D.size();
  }
};

int main() {
  return 0;
}
