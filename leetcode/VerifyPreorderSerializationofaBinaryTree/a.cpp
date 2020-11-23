/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

void printv(const std::vector<std::string>& v) {
  for (const auto& a : v)
    printf("%s ", a.c_str());
  printf("\n");
}

//            i
// 9,3,4,#,#,1,#,#,2,#,6,#,#
// c: 2
class Solution {
 public:
  bool isValidSerialization(std::string s) {
    if (s.empty())
      return false;
    s += ',';
    int i = 0;
    int cap = 1;  // capacity
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ',')
        continue;
      cap--;
      if (cap < 0)
        return false;
      if (s[i-1] != '#')
        cap += 2;
    }
    return cap == 0;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  Solution sln;
  printb(sln.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
  printb(sln.isValidSerialization("1,#"));
  printb(sln.isValidSerialization("9,#,#,1"));
  printb(sln.isValidSerialization("1,#,#,#,#"));
  printb(sln.isValidSerialization("9,#,92,#,#"));
  printb(sln.isValidSerialization("9,3,4,#,#,1,#,#,#,2,#,6,#,#"));
  printb(sln.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
  
  return 0;
}
