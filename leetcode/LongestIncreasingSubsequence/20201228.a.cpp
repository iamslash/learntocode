/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

//              i
//   A: 6 1 5 3 4
// ans: 1 3 4

// 0ms 100.00% 6.4MB 100.00%
// LIS
// O(NlgN) O(N)
class Solution {
 public:
  int lengthOfLIS(const std::vector<int> &A) {
    std::vector<int> ans;
    for (int i = 0; i < A.size(); i++) {
      auto it = std::lower_bound(ans.begin(), ans.end(), A[i]);
      if (it == ans.end())
        ans.push_back(A[i]);
      else
        *it = A[i];
    }
    return ans.size();
  }
};

int main() {
  return 0;
}
