/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// k: 2
// s: aaabcccd
//    a3bc3d
//
//    aabcc
//    a2bc2
//    ac2

// 60ms 80.22% 9.3MB 49.30%
// recursive dynamic programming
// O(N^2) O(N^2)
#define MAXVAL 127
class Solution {
 private:
  int xs(int x) {
    if (x == 1)
      return 0;
    if (x < 10)
      return 1;
    if (x < 100)
      return 2;
    return 3;
  }
  int dfs(vector<vector<int>>& C, string& s, int i, int k) {
    // base
    int n = s.size();
    if (k < 0)
      return MAXVAL;
    if (i >= n || n - i <= k)
      return 0;
    // memo
    int& r = C[i][k];
    if (r >= 0)
      return r;
    // recursion
    r = MAXVAL;
    int cnt[26] = {0,};
    for (int j = i, most = 0; j < n; ++j) {
      most = max(most, ++cnt[s[j]-'a']);
      r = min(r, 1 + xs(most) + dfs(C, s, j+1, k - (j - i + 1 - most)));
    }
    return r;
  }
 public:
  int getLengthOfOptimalCompression(string s, int k) {
    int n = s.size();
    vector<vector<int>> C(n, vector<int>(n, -1));
    return dfs(C, s, 0, k);    
  }
};
