/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 0ms 100.00% 7MB 50.00%
// brute force
// O(N) O(N)
class Solution {
 private:
  string reformat(string s) {
    // base
    if (s.size() == 4) {
      return s.substr(0,2) + '-' + s.substr(2);
    }
    if (s.size() <= 3) {
      return s;
    }    
    // recursion
    return s.substr(0, 3) + '-' + reformat(s.substr(3)); 
  }
 public:
  string reformatNumber(string number) {
    string s;
    for (char c : number) {
      if (c != ' ' && c != '-') {
        s += c;
      }
    }
    return reformat(s);
  }
};
