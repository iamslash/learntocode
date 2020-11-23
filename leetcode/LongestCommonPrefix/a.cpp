/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.size() == 0)
      return "";
    int r = 0;
    char c = strs[0][0];
    while (true) {
      for (int i = 0; i < strs.size(); ++i) {
        if (strs[i].size() <= r || strs[i][r] != c)
          return strs[i].substr(0, r);
      }
      c = strs[0][++r];
    }
    return strs[0];
  }
};

int main() {
  std::vector<std::string> v = {
    "hello",
    "hella",
    "hey"};
  Solution s;
  printf("%s\n", s.longestCommonPrefix(v).c_str());
  return 0;
}
