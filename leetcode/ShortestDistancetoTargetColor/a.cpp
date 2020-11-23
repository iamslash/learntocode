/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 492ms 52.27% 70MB 100.00%
// binary search
// O(NlgN) O(N)
class Solution {
 public:
  std::vector<int> shortestDistanceColor(
      std::vector<int>& C, std::vector<std::vector<int>>& Q) {
    std::vector<std::vector<int>> col2ids(3);
    for (int i = 0; i < C.size(); ++i)
      col2ids[C[i]-1].push_back(i);
    std::vector<int> ans(Q.size(), -1);
    for (int i = 0; i < Q.size(); ++i) {
      int idx = Q[i][0];
      int col = Q[i][1];
      auto& V = col2ids[col-1];
      if (V.empty())
        continue;
      auto itr = std::lower_bound(V.begin(), V.end(), idx);
      auto itl = itr == V.begin() ? V.end() : std::prev(itr);
      int ditr = itr == V.end() ? INT_MAX : *itr - idx;
      int ditl = itl == V.end() ? INT_MAX : idx - *itl;
      ans[i] = std::min(ditl, ditr);
    }
    return ans;
  }
};

int main() {
  return 0;
}
