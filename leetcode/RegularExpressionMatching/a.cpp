/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

//     i
// s : a b
// p : a *
//     j

// p[j-1] != '*' && (s[i-1] == p[j-1] || p[j-1] == '.') : C[i][j] = c[i-1][j-1]
// p[j-1] == '*' a* counts 0 : C[i][j] = C[i][j-2]
// p[j-1] == '*' a* counts at least 1 : C[i][j] = C[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')
//
// 8ms 72.84%
class Solution {
 public:
  bool isMatch(const std::string& s, const std::string& p) {
    int m = s.size(), n = p.size();
    std::vector<std::vector<bool>> C = std::vector<std::vector<bool>>(m+1,
                                       std::vector<bool>(n+1, false));
    C[0][0] = true;
    // pattern for a* a*b* a*b*c*
    for (int j = 1; j <= n; ++j) {
      C[0][j] = p[j-1] == '*' && C[0][j-2];
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j-1] != '*') {
          C[i][j] = (p[j-1] == s[i-1] || p[j-1] == '.') && C[i-1][j-1];
        } else {
          C[i][j] = C[i][j-2] || ((p[j-2] == s[i-1] || p[j-2] == '.') && C[i-1][j]);
        }        
      }
    }
    C[0][0] = true;
    return C[m][n];
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  Solution sln;
  // printb(sln.isMatch("aa", "a"));
  // printb(sln.isMatch("aa", "a*"));
  // printb(sln.isMatch("ab", ".*"));
  // printb(sln.isMatch("aab", "c*a*b"));
  // printb(sln.isMatch("mississippi", "mis*is*p*."));
  printb(sln.isMatch("acb", "a*b"));
  return 0;
}
