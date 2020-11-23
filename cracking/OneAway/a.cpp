// Copyright (C) 2016 by iamslash

// One Away: There are three types of edits that can be performed on
// strings: insert a character, remove a character, or replace a
// character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.

// EXAMPLE
// pale, ple -) true
// pales, pale - ) true
// pale, bale -) true
// pale, bae -) false

// CORNERCASE
//

#include <string>

bool IsOneWayInsertable(const std::string& s0, const std::string& s1) {
  // should be same when compare except one char
  int j = 0;
  for (int i = 0; i < s0.size() && j <= 1 ; ++i) {
    if (s0[i] != s1[i+j])
      ++j;
    // printf("%d %d\n", i, j);
  }
  return j <= 1 ? true : false;
}

bool IsOneWayReplaceble(const std::string& s0, const std::string& s1) {
  // should be same when compare except one char
  int j = 0;
  for (int i = 0; i < s0.size() && j <= 1 ; ++i) {
    if (s0[i] != s1[i])
      ++j;
  }
  return j == 1 ? true : false;
}

bool IsOneWayRemovable(const std::string& s0, const std::string& s1) {
  // should be same when compare except one char
  int j = 0;
  for (int i = 0; i < s1.size() && j <= 1 ; ++i) {
    if (s0[i+j] != s1[i])
      ++j;
    // printf("%d %d\n", i, j);
  }
  return j <= 1 ? true : false;
}

bool IsOneWay(const std::string& s0, const std::string& s1) {
  // 0. insert
  // 1. remove
  // 2. replace
  if ((s0.size() + 1 == s1.size() && IsOneWayInsertable(s0, s1)) ||
      (s0.size() == s1.size() && IsOneWayReplaceble(s0, s1)) ||
      (s0.size() - 1 == s1.size() && IsOneWayRemovable(s0, s1)))
    return true;
  return false;
}

int main() {
  std::string s0 = "pale"; std::string s1 = "ple";
  std::string s2 = "pales"; std::string s3 = "pale";
  std::string s4 = "pale"; std::string s5 = "bale";
  std::string s6 = "pale"; std::string s7 = "bae";
  std::string s8 = "pale"; std::string s9 = "palek";
  printf("%s\n", IsOneWay(s0, s1) ? "true" : "false");
  printf("%s\n", IsOneWay(s2, s3) ? "true" : "false");
  printf("%s\n", IsOneWay(s4, s5) ? "true" : "false");
  printf("%s\n", IsOneWay(s6, s7) ? "true" : "false");
  printf("%s\n", IsOneWay(s8, s9) ? "true" : "false");

  return 0;
}
