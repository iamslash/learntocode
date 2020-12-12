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

// recursive dynamic programming, top to bottom dynamic programming
// O(N^2) o(N^2)
class Solution {
 private:
  int dfs(vector<vector<int>>& C, string& s,
          int i, int j) {
    // base
    if (i > j) {
      return 0;
    }
    if (i == j) {
      return 1;
    }
    // memo
    int& r = C[i][j];
    if (r >= 0) {
      return r;
    }
    // recursion
    if (s[i] == s[j]) {
      r = dfs(C, s, i+1, j-1) + 2;
    } else {
      r = max(dfs(C, s, i+1, j),
              dfs(C, s, i, j-1));
    }
    return r;
  }
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> C(n, vector<int>(n, -1));
    return dfs(C, s, 0, n-1);
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

// iterative dynamic programming
// bottom up dynamic programming
// O(N) O(N^2)
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> C(n, vector<int>(n, -1));
    for (int i = n - 1; i >= 0; --i) {
      C[i][j] = 1;
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          C[i][j] = C[i+1][j-1] + 2;
        } else {
          C[i][j] = max(C[i+1][j], C[i][j-1]);
        }
      }
    }
    return C[0][n-1];
  }
};
