/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

//    l     r
// s: k b b a d

// 28ms 82.16% 7.4MB 89.04%
// linear traversal
// O(N^2) O(1)
class Solution {
 private:
  int maxLo = 0, maxLen = 1;
  void maxPalindrome(string& s, int l, int r) {    
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      l--, r++;
    }
    int len = r - l -1;
    if (len > maxLen) {
      maxLo = l+1;
      maxLen = len;
    }
  }
 public:
  string longestPalindrome(string s) {
    int ans = 1;
    for (int i = 1; i < s.size(); ++i) {
      maxPalindrome(s, i-1, i);
      maxPalindrome(s, i, i);
    }
    return s.substr(maxLo, maxLen);
  }
};

// Time Limit Exceed
// iterative dynamic programming
// O(N^2) O(N^2)
class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    string ans;
    vector<vector<bool>> C(n, vector<bool>(n));
    for (int i = n-1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        C[i][j] = s[i] == s[j] && (j-i<3 || C[i+1][j-1]);
        if (C[i][j] && (ans.empty() || j-i+1 > ans.size()))
          ans = s.substr(i, j-i+1);
      }
    }
    return ans;
  }
};
