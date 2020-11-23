/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 64ms 57.32% 24.3MB 23.46%
// brute force
// O(N) O(1)
class Solution {
 private:
  bool palindrome(string s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r])
        return false;
      l++, r--;
    }
    return true;
  }
 public:
  bool validPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j])
        return palindrome(s, i+1, j) ||
            palindrome(s, i, j-1);
      i++, j--;
    }
    return true;
  }
};
