/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <set>

class Solution {
 public:
  int solve(const std::vector<int>& A, int k) {
    int ans = 0, cum = 0;
    std::set<int> psSet;
    psSet.insert(0);
    for (int i = 0; i < A.size(); i++) {
      cum += A[i];
      auto it = psSet.lower_bound(cum - k);
      if (it != psSet.end())
        ans = std::max(ans, cum - *it);
      psSet.insert(cum);
    }
    return ans;
  }
};

int main() {
  return 0;
}
