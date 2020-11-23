/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 12ms 100.00% 10MB 55.00%
// O(N) O(1)
class Solution {
 public:
  int uniqueLetterString(std::string S) {
    std::vector<std::vector<int>> lr(26, std::vector<int>(2, -1));
    int n    = S.size();
    int mod  = 1e9 + 7;
    int rslt = 0;
    for (int i = 0; i < n; ++i) {
      int j = S[i] - 'A';
      rslt = (rslt + (i - lr[j][1]) * (lr[j][1] - lr[j][0]) % mod) % mod;
      lr[j][0] = lr[j][1];
      lr[j][1] = i;
    }
    for (int j = 0; j < 26; ++j) {
      rslt = (rslt + (n - lr[j][1]) * (lr[j][1] - lr[j][0]) % mod) % mod;
    }
    return rslt;
  }
};

int main() {

  std::string S = "ABC";
  // std::string S = "ABA";

  Solution sln;

  printf("%d\n", sln.uniqueLetterString(S));
  
  return 0;
}
