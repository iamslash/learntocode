/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

// 20ms 28.16% 7.5MB 52.80%
// hash map
// O(N) O(N)
class Solution {
 public:
  bool canConvert(string s, string t) {
    if (s == t)
      return true;
    unordered_map<char, char> C;
    for (int i = 0; i < s.length(); ++i) {
      if (C.count(s[i]) > 0 && C[s[i]] != t[i])
        return false;
      C[s[i]] = t[i];
    }
    return set<char>(t.begin(), t.end()).size() < 26;
  }
};
