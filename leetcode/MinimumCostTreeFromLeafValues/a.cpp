/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 4ms 80.81% 8.3MB 100.00%
// monotone decreasing stack
// O(N) O(N)
class Solution {
 public:
  int mctFromLeafValues(std::vector<int>& A) {
    int ans = 0, n = A.size();
    std::vector<int> stck = {INT_MAX};
    for (int a : A) {
      while (stck.back() <= a) {
        int mi = stck.back(); stck.pop_back();
        ans += mi * std::min(stck.back(), a);
      }
      stck.push_back(a);
    }
    for (int i = 2; i < stck.size(); ++i) {
      ans += stck[i] * stck[i-1];
    }
    return ans;
  }
};

int main() {
  return 0;
}
