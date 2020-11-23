/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 28ms 97.56% 6.6MB 96.56%
// dynamic programming interative way
// O(N^2) O(N)
class Solution {
 private:
  int longestPalindromeSubseq(const string& s) {
    int n = s.size();
    // C[i] : longest palindrom subseq start from i
    vector<int> C(n, 1);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      int len = 0;
      for (int j = i - 1; j >= 0; --j) {
        int tmp = C[j];
        if (s[j] == s[i])
          C[j] = len + 2;
        len = max(len, tmp);
      }
    }
    for (int i : C)
      ans = max(ans, i);
    return ans;
  }
 public:
  int minInsertions(string s) {
    return s.size() - longestPalindromeSubseq(s);
  }
};
