/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 4,  4: a b a b a b a b
// 4,  3: a b a b a b a
// 4,  2: a a b a a b

// 5,  2: aabaaba
// 5,  3; abb

// 0ms 100.00% 8.5MB 68.60%
// greedy
// O(A+B) O(A+B)
class Solution {
 private:
  std::string solve(char cx, int nx, char cy, int ny) {
    std::string ans;
    while (nx-- > 0) {
      ans += cx;
      if (nx > ny)
        nx--, ans += cx;
      if (ny-- > 0)
        ans += cy;
    }
    return ans;
  }
 public:
  std::string strWithout3a3b(int A, int B) {
    if (A < B)
      return solve('b', B, 'a', A);
    return solve('a', A, 'b', B);
  }
};

int main() {
  return 0;
}
