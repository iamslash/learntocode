/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 36ms 93.15% 12.5MB 46.01%
// O(N) O(1)
class Solution {
 public:
  int numSubarrayBoundedMax(std::vector<int>& A, int L, int R) {
    int cnt = 0, j = 0, k = 0;
    for (int a : A) {
      j = (a  < L) ? ++j : 0;
      k = (a <= R) ? ++k : 0;
      cnt += k - j;
    }
    return cnt;
  }
};

int main() {
  return 0;
}
