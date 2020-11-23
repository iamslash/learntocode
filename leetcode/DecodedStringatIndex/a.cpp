/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

//       i
//   S: leet2code3
//   K: 2
// len: 2

// 4ms 72.47% 8.3MB 39.01%
// O(N) O(1)
class Solution {
 public:
  std::string decodeAtIndex(std::string S, int K) {
    int64_t len = 0, i;
    for (i = 0; len < K; ++i)
      len = std::isdigit(S[i]) ? len * (S[i] - '0') : len + 1;
    while (i--) {
      // printf("S[%d]: %c, len:%d, K:%d\n", i, S[i], len, K);
      if (std::isdigit(S[i])) {
        len /= S[i] - '0';
        K %= len;
      } else if (K % len-- == 0) {
        return std::string(1, S[i]);
      }
    }
    return "";
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.decodeAtIndex("leet2code3", 6).c_str());
  
  return 0;
}
