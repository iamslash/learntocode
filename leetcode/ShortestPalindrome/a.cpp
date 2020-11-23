/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

//                                 i
//    S: a a c e c a a a # a a a c e c a a
//             j
// pi[]: 0 1 0 0 0 1 2 2 0 1 2 2 3 4 5 6 7

// 8ms 83.52% 10.3MB 17.10%
// kmp algorithm
// O(H) O(H)
class Solution {
 public:
  std::string shortestPalindrome(std::string H) {
    std::string R = H;
    std::reverse(R.begin(), R.end());
    std::string S = H + "#" + R;

    std::vector<int> pi(S.size(), 0);
    for (int i = 1; i < S.size(); ++i) {
      int j = pi[i-1];
      while (j > 0 && S[i] != S[j])
        j = pi[j - 1];
      pi[i] = (j += S[i] == S[j]);
    }
    return R.substr(0, H.size() - pi[S.size() - 1]) + H;
  }
};

int main() {
  std::string s = "aacecaaa"; // aaacecaaa
  // std::string s = "abcd";  // dcbabcd
  Solution sln;
  printf("%s\n", sln.shortestPalindrome(s).c_str());
  
  return 0;
}
