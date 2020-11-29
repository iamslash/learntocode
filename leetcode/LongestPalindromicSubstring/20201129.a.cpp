/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// l
//     r
//   a 

// 20ms 91.06% 7.3MB 5.58%
// linear traversal
// O(N^2) O(1)
class Solution {
 private:
  int lo, maxLen;
  void maxPal(string& s, int l, int r) {
    int n = s.size();
    while (l >= 0 && r < n && s[l] == s[r]) {
      l--;
      r++;
    }
    int len = r - l - 1;
    if (maxLen < len) {
      lo = l + 1;
      maxLen = len;
    }
  }
 public:
  string longestPalindrome(string s) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
      maxPal(s, i, i);
      maxPal(s, i, i+1);
    }
    return s.substr(lo, maxLen);
  }
};

// 1932ms 5.05% 47.8MB 5.58%
// dynamic programming
// O(N^2) O(N^2)
class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    string ans;
    vector<vector<bool>> C(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        C[i][j] = s[i] == s[j] && (j - i < 3 || C[i+1][j-1]);
        if (C[i][j] && (ans.empty() || j - i + 1 > ans.size()))
          ans = s.substr(i, j - i + 1);
      }
    }
    return ans;
  }
};
