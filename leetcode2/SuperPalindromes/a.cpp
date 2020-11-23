/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 304ms 55.45% 35.5MB 42.57%
// brute force
class Solution {
 private:
  int64_t genPalindrome(int n, int type) {
    int64_t x = n;
    int64_t y = n;
    if (type == 1) {
      x /= 10;
    }
    while (y > 0) {
      x = x * 10 + y % 10;
      y /= 10;
    }
    return x;
  }
  bool isPalindrome(int64_t n) {
    string s = to_string(n);
    int i = 0, j = s.size()-1;
    while (i < j) {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }  
 public:
  int superpalindromesInRange(string L, string R) {
    int64_t l = stoll(L);
    int64_t r = stoll(R);
    int ans = 0;
    for (int i = 0; i < 1e5; ++i) {
      for (int type = 0; type < 2; ++type) {
        int64_t pal = genPalindrome(i, type);
        if (pal > 1e9)
          continue;
        int64_t pp = pal*pal;
        if (pp >= l && pp <= r && isPalindrome(pp)) {
          ans++;
        }            
      }
    }
    return ans;
  }
};
