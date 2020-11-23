/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 4ms 82.36% 6MB 83.24%
// DFS, back tracking
// O(2^N) O(N)
class Solution {
 private:
  string best;
  int cnt;
  int len;
  void dfs(string cand) {
    // base
    if (cand.size() == len) {
      cnt--;
      if (cnt == 0) {
        best = cand;
      }
      return;
    }
    if (best.size() > 0)
      return;

    // recursion
    for (char c = 'a'; c <= 'c'; ++c) {
      if (cand.size() > 0 && cand.back() == c)
        continue;
      dfs(cand + c);
    }
  }
 public:
  string getHappyString(int n, int k) {
    len = n;
    cnt = k;
    dfs("");
    return best;
  }
};
