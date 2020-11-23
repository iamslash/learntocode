/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 4ms 100.00% 9.3MB 8.11%
// O(N) O(N) 
class Solution {
 public:
  std::vector<std::string> removeComments(
      std::vector<std::string>& src) {
    std::vector<std::string> r;
    int st = 0; // 0: source, 1: /*
    for (auto& s : src) {
      int n = s.size();
      std::string ss;
      if (!r.empty() && st == 1) {
        ss = r.back();
        r.pop_back();
      }
      for (int i = 0; i < n; ++i) {
        if (st == 0) {
          if (i < n-1 && s[i] == '/' && s[i+1] == '/') {
            break;
          } else if (i < n-1 && s[i] == '/' && s[i+1] == '*') {
            st = 1;
            ++i;
          } else {
            ss += s[i];
          }
        } else {
          if (i < n-1 && s[i] == '*' && s[i+1] == '/') {
            st = 0;
            ++i;
          }
        }
      }
      if (!ss.empty())
        r.push_back(ss);
    }
    return r;
  }
};

int main() {

  std::vector<std::string> s = {
    "/*Test program */",
    "int main()",
    "{ ",
    "  // variable declaration ",
    "int a, b, c;",
    "/* This is a test",
    "   multiline  ",
    "   comment for ",
    "   testing */",
    "a = b + c;", "}"
  };
  // std::vector<std::string> s = {
  //   "a/*comment",
  //   "line",
  //   "more_comment*/b"
  // };
  Solution sln;
  auto r = sln.removeComments(s);
  for (auto& s : r)
    printf("%s\n", s.c_str());
  
  return 0;
}
