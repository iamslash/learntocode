/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 56ms 99.69% 20.9MB 17.03%
// recursive dynamic programming
// O(N) O(N)
#define MOD 1000000007
class Solution {
 private:
  int dfs(vector<int>& C, string& s, int64_t k, int i) {
    // base
    int n = s.size();
    if (i == n)
      return 1;
    if (s[i] == '0')
      return 0;
    // memo
    int& r = C[i];
    if (r > -1)
      return r;
    r = 0;
    int64_t num = 0;
    for (int j = i; j < n; ++j) {
      num = num * 10 + s[j] - '0';
      if (num > k)
        break;
      r = (r + dfs(C, s, k, j+1)) % MOD;
    }
    return r;
  }
 public:
  int numberOfArrays(string s, int k) {
    vector<int> C(s.size(), -1);
    return dfs(C, s, k, 0);
  }
};
