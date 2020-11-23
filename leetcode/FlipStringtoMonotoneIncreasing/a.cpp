/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 00110
// 010110
// 00011000

// // 12ms 48.37%
// // O(N) O(N)
// class Solution {
//  public:
//   int minFlipsMonoIncr(std::string s) {
//     int r = INT_MAX, n = s.size();
//     std::vector<int> l2r(n+1), r2l(n+1);
//     for (int i = 1, j = n - 1; j >= 0; ++i, --j) {
//       l2r[i] += l2r[i-1] + (s[i-1] == '0' ? 0 : 1);
//       r2l[j] += r2l[j+1] + (s[j] == '1' ? 0 : 1);
//     }
//     for (int i = 0; i <= n; ++i)
//       r = std::min(r, l2r[i] + r2l[i]);
//     return r;
//   }
// };

// 8ms 92.53% 9.3MB 68.99%
// O(N) O(1)
class Solution {
 public:
  int minFlipsMonoIncr(std::string s) {
    int r = 0, ones = 0;
    for (char c : s) {
      if (c == '1')
        ones += 1;
      else
        r = std::min(r + 1, ones);
    }
    return r;
  }
};

int main() {
  return 0;
}
