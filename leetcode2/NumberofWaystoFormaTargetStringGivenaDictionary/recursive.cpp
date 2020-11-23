/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 300ms 71.89% 79.5MB 5.05%
// recursive dynamic programming
// O(WT) O(WT)
#define MOD 1000000007
class Solution {
 private:
  int64_t dfs(vector<vector<int64_t>>& C, vector<vector<int>>& freqs,
          string& target, int i, int j) {
    // printf("i: %d, j: %d\n", i, j);
    int m = C.size() - 1, t = target.size();
    // base
    if (j >= t)
      return 1;
    if (i >= m)
      return 0;
    // memo
    int64_t& r = C[i][j];
    if (r >= 0)
      return r;
    // recursion
    r = 0;
    r = (r + dfs(C, freqs, target, i+1, j)) % MOD;
    r = (r + freqs[i][target[j]-'a'] * dfs(C, freqs, target, i+1, j+1) % MOD) % MOD; 
    return r;
  }
 public:
  int numWays(vector<string>& words, string target) {
    int n = words.size(), m = words[0].size();
    vector<vector<int>> freqs(m, vector<int>(26));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        string& word = words[i];
        freqs[j][word[j] - 'a']++;
      }
    }
    vector<vector<int64_t>> C(m + 1, vector<int64_t>(target.size() + 1, -1));
    return dfs(C, freqs, target, 0, 0);
  }
};
