/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 2376ms 66.27% 459.5MB 14.59%
// rabinkarp, binary search
#define PRIME 10000007
class Solution {
 private:
  vector<int> powers;
  string rabinkarp(string s, int len) {
    if (len == 0)
      return "";
    int n = s.size(), cur = 0;
    unordered_map<int, vector<int>> hash;
    for (int i = 0; i < len; ++i) {
      cur = (cur * 26 + (s[i] - 'a')) % PRIME;
    }
    hash[cur] = {0};
    for (int i = len; i < n; ++i) {
      cur = ((cur - powers[len-1] * (s[i-len] - 'a')) % PRIME + PRIME) % PRIME;
      cur = (cur * 26 + (s[i] - 'a')) % PRIME;

      if (hash.find(cur) == hash.end()) {
        hash[cur] = {i - len + 1};
      } else {
        for (int index : hash[cur]) {
          if (s.substr(index, len) == s.substr(i - len + 1, len))
            return s.substr(index, len);
        }
        hash[cur].push_back({i - len + 1});
      }      
    }
    return "";
  }
 public:
  string longestDupSubstring(string s) {
    int n = s.size(), lo = 0, hi = n-1;
    powers = vector<int>(n);
    powers[0] = 1;
    for (int i = 1; i < n; ++i) {
      powers[i] = (powers[i-1] * 26) % PRIME;
    }
    string ans;
    while (lo <= hi) {
      int mi = lo + (hi - lo) / 2;
      string dup = rabinkarp(s, mi);
      if ((int)dup.size() > (int)ans.size()) {
        ans = dup;
        lo = mi + 1;
      } else {
        hi = mi - 1;
      }
    }
    return ans;    
  }
};
