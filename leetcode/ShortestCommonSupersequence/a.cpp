/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 312ms 23.74% 301.7MB 100.00%
// dynamic programming
// O(MN) O(MN)
class Solution {
  private:
  std::string lcs(std::string& a, std::string& b) {
    int m = a.size(), n = b.size();
    std::vector<std::vector<std::string>> C(
        m + 1,
        std::vector<std::string>(n + 1, ""));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i] == b[j])
          C[i+1][j+1] = C[i][j] + a[i];
        else
          C[i+1][j+1] = C[i+1][j].size() > C[i][j+1].size() ?
              C[i+1][j] : C[i][j+1];
      }
    }
    return C[m][n];
  }
 public:
  std::string shortestCommonSupersequence(
      std::string a, std::string b) {
    int i = 0, j = 0;
    std::string ans;
    std::string l = lcs(a, b);
    for (char c : l) {
      while (a[i] != c)
        ans += a[i++];
      while (b[j] != c)
        ans += b[j++];
      ans += c;
      ++i, ++j;
    }
    return ans + a.substr(i) + b.substr(j);
  }
};

int main() {
  return 0;
}
