/* Copyright (C) 2020 by iamslash */
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#define PRIME 1000000007
class Solution {
 private:
  vector<int> powers;
 public:
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
      // Remove one character from hash-value
      cur = ((cur - powers[len-1] * (s[i-len] - 'a')) % PRIME + PRIME) % PRIME;
      // Add one character to hash-value
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
};
