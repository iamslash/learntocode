/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;


// 2
// 1 2 3 4 5 6
//
// 5 6 4 3 1 2

// 416ms 80.00% 66.3MB 60.00%
// DFS
// O(2^N) O(N)
class Solution {
 private:
  unordered_set<string> seen;
  string best;
  int a, b;
  int n;
  string rotate(string s, int k) {
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    return s;
  }
  string add(string s, int k) {
    for (int i = 1; i < n; i += 2) {
      char& c = s[i];
      c = '0' + (c - '0' + k) % 10;
    }
    return s;
  }
  void dfs(string s) {
    // base
    if (seen.count(s) > 0)
      return;
    seen.insert(s);
    best = min(best, s);
    // recursion
    dfs(rotate(s, b));
    dfs(add(s, a));
  }
 public:
  string findLexSmallestString(string s, int a, int b) {
    best = s;
    this->a = a;
    this->b = b;
    n = s.size();
    dfs(s);
    return best;
  }
};
