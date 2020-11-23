/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_map>

void printm(std::unordered_map<char, int>& m) {
  for (auto& pr : m)
    printf("%c:%d ", pr.first, pr.second);
  printf("\n");
}

// 4ms 100.00% 8.6MB 40.00%
class Solution {
 public:
  bool isOneEditDistance(std::string s, std::string t) {
    int m = s.size();
    int n = t.size();
    if (m > n)
      return isOneEditDistance(t, s);
    for (int i = 0; i < m; ++i) {
      if (s[i] != t[i]) {
        if (m == n)
          return s.substr(i+1) == t.substr(i+1);
        return s.substr(i) == t.substr(i+1);
      }
    }
    return m + 1 == n;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

// teacher
// detacher

int main() {

  Solution sln;
  // printb(sln.isOneEditDistance("cb", "ab"));
  // printb(sln.isOneEditDistance("reacher", "teacher"));
  // printb(sln.isOneEditDistance("teacher", "reacher"));
  printb(sln.isOneEditDistance("teacher", "detacher"));
  return 0;
}
