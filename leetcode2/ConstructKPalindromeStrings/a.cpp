/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <bitset>

using namespace std;

// 96ms 49.49% 11.8MB 90.64%
// bit manipulation
// O(N) O(1)
class Solution {
public:
    bool canConstruct(string s, int k) {
      bitset<26> b;
      for (char c : s) {
        b.flip(c - 'a');
      }
      return b.count() <= k && k <= s.size();
    }
};
