/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

// anagram 
// a n g r m
// 3 1 1 1 1
//
//      i
// mangaar
// a n g r m
// 0 0 0 0 0

// friend 
// f r i e n d
// 1 1 1 1 1 1
//
//      i
// family
// f r i e n d a m l y
// 0 1 0 1 1 1-1-1-1-1

// leetcode
// l e t c o d
// 1 3 1 1 1 1
// practice
//        i
// l e t c o d p r a i
// 1 2 0-1 1 1-1-1-1-1

// // 188ms 31.03% 16.6MB 100.00%
// // hash map
// // O(N) O(1)
// class Solution {
//  public:
//   int minSteps(string s, string t) {
//     int cnts[26] = {};
//     for (char c : s)
//       cnts[c-'a']++;
//     for (char c : t)
//       cnts[c-'a']--;
//     int ans = 0;
//     for (int n : cnts)
//       if (n > 0)
//         ans += n;
//     return ans;
//   }
// };

// 184ms 31.64% 16.4MB 100.00%
// hash map
// O(N) O(1)
class Solution {
 public:
  int minSteps(string s, string t) {
    int cnts[26] = {};
    for (int i = 0; i < s.size(); ++i) {
      ++cnts[s[i] - 'a'];
      --cnts[t[i] - 'a'];
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i)
      ans += abs(cnts[i]);
    return ans >> 1;
  }
};
