/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

//       
// s:   0 b b a b a b
//    0 1
//    b   1 
//    b     1
//    a       1
//    b         1
//    a           1 
//    b             1

// 800ms 22.73% 258.8MB 22.73%
// recursive dynamic programming
// top down  dynamic programming
// O(N^2) o(N^2)
class Solution {
 private:
  int dfs(vector<vector<vector<int>>>& C, string& s,
          int i, int j, int x) {
    // base
    if (i >= j) {
      return 0;
    }
    // memo
    int& r = C[i][j][x];
    if (r >= 0) {
      return r;
    }
    // recursion
    r = max(dfs(C, s, i+1, j, x),
            dfs(C, s, i, j-1, x));
    if (s[i] == s[j] && s[i] - 'a' != x) {
      r = max(r, 2 + dfs(C, s, i+1, j-1, s[i] - 'a'));
    }    
    return r;
  }
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<vector<int>>> C(
        n, vector<vector<int>>(
            n, vector<int>(27, -1)));
        return dfs(C, s, 0, n-1, 26);
  }
};

//       
// s:   b b a b a b
//    b 1 2 2 3 3 5 
//    b   1 1 3 3 5
//    a     1 1 3 3
//    b       1 1 3
//    a         1 1
//    b           1

// 136ms 72.73% 13.7MB 31.82%
// iterative dynamic programming
// bottom up dynamic programming
// O(N^2) O(N^2)
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.length();
    int C[250][250][26] = {0,};
    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = 0; k < 26; ++k) {
          if (s[i] == s[j] && k != s[i]-'a') {
            C[i][j][s[i]-'a'] = max(C[i][j][s[i]-'a'],
                                    C[i+1][j-1][k]+2);
          } else {
            C[i][j][k] = max(C[i][j][k],
                             max(C[i+1][j][k],
                                 C[i][j-1][k]));
          }
        }
      }
    }
    int ans = 0;
    for (int k = 0; k < 26; ++k) {
      ans = max(ans, C[0][n-1][k]);
    }
    return ans;
  }
};
