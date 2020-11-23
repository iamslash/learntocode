/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// a: a b d e f
//              .
// b: f e c a b

// 80ms 89.50% 24.6MB 5.02%
// linear traversal
// O(N) O(1)
class Solution {
 private:
  bool palindrome(string& s, int i, int j) {
    while (i < j && s[i] == s[j]) {
      i++, j--;
    }
    return i >= j;
  }
  bool traverse(string& a, string& b) {
    int n = a.size(), i = 0, j = a.size() - 1;
    while (i < j && a[i] == b[j]) {
      ++i, --j;
    }
    return palindrome(a, i, j) || palindrome(b, i, j);
  }
 public:
  bool checkPalindromeFormation(string a, string b) {
    return traverse(a, b) || traverse(b, a);
  }
};
