/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// // 16ms 25.69% 19.5MB 100.00%
// // greedy approach
// // O(N) O(1)
// class Solution {
//  public:
//   int longestDecomposition(std::string s) {
//     int ans = 0, n = s.size();
//     std::string l = "", r = "";
//     for (int i = 0; i < n; ++i) {
//       l = l + s[i];
//       r = s[n - i - 1] + r;
//       if (l == r) {
//         ++ans;
//         l = "";
//         r = "";
//       }
//     }
//     return ans;
//   }
// };

// 0ms 100.00% 9.5MB 100.00%
// recursive way
// O(N) O(N)
class Solution {
 public:
  int longestDecomposition(std::string s, int ans = 0) {
    int n = s.size();
    for (int l = 1; l <= n / 2; ++l) {
      if (s[0] == s[n-l] && s[l-1] == s[n-1])
        if (s.substr(0, l) == s.substr(n-l))
          return longestDecomposition(s.substr(l, n - l - l), ans + 2);
    }
    return n ? ans + 1 : ans;
  }
};

int main() {
  return 0;
}
