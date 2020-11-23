/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 8ms 76.48% 9.8MB 75.45%
// iterative way
// O(N^2) O(N^2)
class Solution {
 public:
  std::vector<int> numsSameConsecDiff(int N, int K) {
    std::vector<int> ans = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    while (--N > 0) {
      std::vector<int> tmp;
      for (int a : ans) {
        int b = a % 10;
        if (a > 0 && b + K < 10)
          tmp.push_back(a * 10 + b + K);
        if (a > 0 && K > 0 && b - K >= 0)
          tmp.push_back(a * 10 + b - K);
      }
      ans = tmp;
    }
    return ans;
  }
};

int main() {
  return 0;
}
