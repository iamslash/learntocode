/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

//           i    
//    s: a a b
// cuts:-1 0 0 1

// 9ms 100.00%
// O(N^2) O(N)
class Solution {
 public:
  int minCut(std::string s) {
    int n = s.size();
    if (n <= 1)
      return 0;
    int i, j, cuts[n+1];
    for (i = 0; i <= n; ++i)
      cuts[i] = i-1;
    for (i = 1; i < n; ++i) {
      printf("i: %d\n", i);
      // odd palindrome
      for (j = 0; i - j >= 0 && i + j < n && s[i-j] == s[i+j]; ++j) {
        cuts[i+j+1] = std::min(cuts[i+j+1], 1 + cuts[i-j]);
        printf(" odd: %d, cuts: %d\n", i+j+1, cuts[i+j+1]);
      }
      // even palindrome
      for (j = 0; i - j - 1 >= 0 && i + j < n && s[i-j-1] == s[i+j]; ++j) {
        cuts[i+j+1] = std::min(cuts[i+j+1], 1 + cuts[i-j-1]);
        printf(" eve: %d, cuts: %d\n", i+j+1, cuts[i+j+1]);
      }
    }
    return cuts[n];
  }
};

int main() {
  std::string s = "aab";
  Solution sln;
  printf("%d\n", sln.minCut(s));
  
  return 0;
}
