/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

// 252ms 60.00% 6.9MB 18.00%
// brute force
// O(N^2) O(1)
class Solution {
 private:
  int64_t palindrome(int n) {
    string s = to_string(n);
    string r = s;
    reverse(r.begin(), r.end());
    return stol(s + r);
  }
 public:
  int largestPalindrome(int n) {
    if (n == 1)
      return 9;
    int upper = pow(10, n) - 1;
    int lower = pow(10, n - 1);
    for (int i = upper; i >= lower; --i) {
      int64_t cand = palindrome(i);
      for (int64_t j = upper; j*j >= cand; --j) {
        if (cand % j == 0 && cand / j <= upper) {
          return cand % 1337;
        }
      }
    }
    return -1;
  }
};

