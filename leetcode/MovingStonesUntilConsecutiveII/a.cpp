/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// i
// 1 2 99 100
//   j
//      k

// 32ms 75.78% 9.7MB 100.00%
// O(NlgN) O(1)
class Solution {
 public:
  std::vector<int> numMovesStonesII(std::vector<int>& S) {
    std::sort(S.begin(), S.end());
    int n = S.size(), mincnt = n;
    for (int i = 0, j = 0; j < n; ++j) {
      while (S[j] - S[i] + 1 > n)
        ++i;
      int k = j - i + 1;
      if (k == n-1 && S[j] - S[i] + 1 == n-1) {
        mincnt = std::min(mincnt, 2);
      } else {
        mincnt = std::min(mincnt, n - k);
      }
    }
    return {mincnt,
          std::max(S[n-1] - S[1] - (n - 2),
                   S[n-2] - S[0] - (n - 2))};
  }
};

int main() {
  return 0;
}
