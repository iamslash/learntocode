/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

// 20ms 86.57% 10.6MB 58.03%
// O(N) O(N)
class Solution {
 public:
  int flipgame(std::vector<int>& F, std::vector<int>& B) {
    int rslt = INT_MAX;
    int n = F.size();
    std::unordered_set<int> same;
    for (int i = 0; i < n; ++i)
      if (F[i] == B[i])
        same.insert(F[i]);
    for (int a : F) {
      if (!same.count(a))
        rslt = std::min(rslt, a);
    }
    for (int a : B) {
      if (!same.count(a))
        rslt = std::min(rslt, a);
    }

    return rslt == INT_MAX ? 0 : rslt;
  }
};

int main() {
  return 0;
}
