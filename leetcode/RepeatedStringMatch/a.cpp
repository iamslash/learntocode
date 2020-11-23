/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/google/67/sql-2/469/

#include <cstdio>
#include <string>


// abcd
// abcdabcd
// abcdabcdabcd
//
// abcdabcd
// bcdabcda
// cdabcdab
// dabcdabc

class Solution {
 public:
  int repeatedStringMatch(std::string A, std::string B) {
    int r = 1;
    int a = A.size();
    std::string s = A;
    // attatch A string minimally
    while (s.size() < B.size()) {
      s += A;
      ++r;
    }
    if (s.find(B) != std::string::npos)
      return r;

    // attatch again
    s += A;
    ++r;
    if (s.find(B) == std::string::npos)
      return -1;
    return r;
  }
};

int main() {
  Solution s;
  // printf("%d\n", s.repeatedStringMatch("abcd", "cdabcdab"));
  // printf("%d\n", s.repeatedStringMatch("a", "aa"));
  printf("%d\n", s.repeatedStringMatch("axaxaya", "axaya"));
  return 0;
}
