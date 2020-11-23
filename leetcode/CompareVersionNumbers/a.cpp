// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <string>

class Solution {
 public:
  int compareVersion(std::string a, std::string b) {
    int rslt = 0;
    int i = 0, j = 0;
    std::string aa, bb;
    while (i < a.size() || j < b.size()) {
      while (i < a.size() && a[i] != '.') {
        aa += a[i++];
      }
      while (j < b.size() && b[j] != '.') {
        bb += b[j++];
      }
      ++i, ++j;
      //
      // printf("%s %s\n", aa.c_str(), bb.c_str());
      if (aa.empty() && bb.empty()) {
        return 0;
      } else if (aa.empty() && !bb.empty()) {
        if (std::stoi(bb) > 0)
          return -1;
      } else if (!aa.empty() && bb.empty()) {
        if (std::stoi(aa) > 0)
          return 1;
      } else {
        int na = std::stoi(aa);
        int nb = std::stoi(bb);
        if (na > nb)
          return 1;
        else if (na < nb)
          return -1;
      }
      aa = bb = "";
    }
    return rslt;
  }
};

int main() {
  Solution s;
  // printf("%d\n", s.compareVersion("0.1", "1.1"));
  // printf("%d\n", s.compareVersion("1.0.1", "1"));
  // printf("%d\n", s.compareVersion("7.5.2.4", "7.5.3"));
  // printf("%d\n", s.compareVersion("1", "1.1"));
  printf("%d\n", s.compareVersion("1.0", "1"));
  return 0;
}
