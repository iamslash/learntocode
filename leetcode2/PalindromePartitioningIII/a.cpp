/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// 12ms 86.71% 6.7MB 73.23%
// dynamic programming
// O(SK) O(SK)
class Solution {
 private:
  int needForPalindrome(string&s, int i, int j) {
    int ans = 0;
    while (i < j) {
      if (s[i++] != s[j--])
        ans++;
    }
    return ans;
  }
  int dfs(vector<vector<int>>& C, string& s, int i, int k) {
    // printf("i: %d, k: %d\n", i, k);
    int n = s.size();
    // base
    if (i >= n || k == 0)
      return 0;
    if (k == 1)
      return needForPalindrome(s, i, n-1);

    // memo
    int& r = C[i][k];
    if (r >= 0)
      return r;

    // recursion
    r = INT_MAX;
    for (int j = i; j < n-k+1; ++j) {
      r = min(r, needForPalindrome(s, i, j) + dfs(C, s, j+1, k-1));
    }
    return r;
  }
 public:
  int palindromePartition(string s, int k) {
    vector<vector<int>> C(s.size(), vector<int>(101, -1));
    return dfs(C, s, 0, k);
  }
};
