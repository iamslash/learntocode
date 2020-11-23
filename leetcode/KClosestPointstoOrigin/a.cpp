/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <numeric>

// 236ms 75.95% 39.8MB 74.23%
// O(NlgN) O(N)
class Solution {
 public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& P, int K) {
    int n = P.size();
    std::vector<int> I(n);
    std::iota(I.begin(), I.end(), 0);
    std::sort(I.begin(), I.end(), [&P](int i, int j) {
        return P[i][0]*P[i][0] + P[i][1]*P[i][1] <
          P[j][0]*P[j][0] + P[j][1]*P[j][1];
      });
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < K; ++i)
      ans.push_back({P[I[i]][0], P[I[i]][1]});
    return ans;
  }
};

int main() {
  return 0;
}
