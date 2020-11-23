/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// a: abc
// b:  bcdef

class Solution {
 private:
  bool startsWith(const string& a, const string& b) {
    if (b.size() < b.size())
      return false;
    for (int i = 0; i < b.size(); ++i) {
      if (a[i] != b[i])
        return false;
    }
    return true;
  }
  int dist(const string& a, const string& b) {
    for (int i = 1; i < a.size(); ++i) {
      if (startsWith(b, a.substr(i)))
        return b.size() - a.size() + i;
    }
    return b.size();
  }
 public:
  string shortestSuperstring(vector<string>& A) {
    
  }
};
