/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 8ms 87.08% 9.6MB 44.29%
// four pointers
// O(SW) O(1)
class Solution {
 private:
  bool isValid(std::string s, std::string w) {
    int ns = s.size(), nw = w.size(), i = 0, j = 0;
    for (int k = 0, l = 0; i < ns && j < nw; i = k, j = l) {
      if (s[i] != w[j])
        return false;
      while (k < ns && s[k] == s[i])
        ++k;
      while (l < nw && w[l] == w[j])
        ++l;
      if (k - i != l - j && k - i < std::max(3, l - j))
        return false;
    }
    return i == ns && j == nw;
  }
 public:
  int expressiveWords(std::string s, std::vector<std::string>& W) {
    int rslt = 0;
    for (auto& w : W)
      if (isValid(s, w))
        ++rslt;
    return rslt;
  }
};

int main() {

  std::string S = "heeellooo";
  std::vector<std::string> W = {"hello", "hi", "helo"};

  Solution sln;
  printf("%d\n", sln.expressiveWords(S, W));

  return 0;
}
