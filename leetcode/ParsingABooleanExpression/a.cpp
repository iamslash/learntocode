/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 8ms 83.16% 9.3MB 100.00%
// dfs
// O(N) O(N)
class Solution {
 private:
  bool dfs(std::string& s, int& i) {
    if (s[i] == 't') {
      ++i;
      return true;
    }
    if (s[i] == 'f') {
      ++i;
      return false;
    }
    if (s[i] == '!')
      return dfs_not(s, i);
    if (s[i] == '&')
      return dfs_and(s, i);
    return dfs_or(s, i);
  }
  bool dfs_not(std::string& s, int& i) {
    i += 2;
    bool b = dfs(s, i);
    i += 1;
    return !b;
  }
  bool dfs_and(std::string& s, int& i) {
    i += 2;
    bool b = dfs(s, i);
    while (s[i] == ',')
      b &= dfs(s, ++i);
    i += 1;
    return b;
  }
  bool dfs_or(std::string& s, int& i) {
    i += 2;
    bool b = dfs(s, i);
    while (s[i] == ',')
      b |= dfs(s, ++i);
    i += 1;
    return b;
  }  
 public:
  bool parseBoolExpr(std::string expr) {
    int i = 0;
    return dfs(expr, i);
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  Solution sln;

  // printb(sln.parseBoolExpr("!(f)"));
  // printb(sln.parseBoolExpr("|(f,t)"));
  // printb(sln.parseBoolExpr("&(t,f)"));
  printb(sln.parseBoolExpr("|(&(t,f,t),!(t))"));
  
  return 0;
}
