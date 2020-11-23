// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/word-break/description/

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& d) {
    std::vector<bool> f(s.size() + 1);
    f[s.size()] = true;
    for (int i = s.size() - 1; i >= 0; --i) {
      for (const auto& w : d) {
        if (i + w.size() <= s.size() &&
            f[i + w.size()] &&
            !strncmp(&s[i], w.c_str(), w.size())) {
          f[i] = true;
          break;
        }
      }
    }
    return f[0];
  }
};


int main() {
  Solution s;
  // std::string a = "leetcode";
  std::string a = "leecode";
  std::vector<std::string> b = {"leet", "code"};
  printf("%d\n", s.wordBreak(a, b));
  return 0;
}
