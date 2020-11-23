/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// words:
//          i
//    a c c a
//    b b b b
//    c a c a
//
// cnt: a b c ... z
//      2 1 0     0
//
// target:
//
//    j
//    a b a
// C: 1 4 5 6
//        

// 292ms 75.26% 28.4MB 5.05%
// iterative dynamic programming
// O(N^2) O(N)
#define MOD 1000000007
class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    int n = target.length();
    vector<int64_t> C(n+1);
    C[0] = 1;
    for (int i = 0; i < words[0].length(); ++i) {
      vector<int> cnt(26);
      for (auto& word : words) {
        cnt[word[i] - 'a']++;
      }
      for (int j = n - 1; j >= 0; --j) {
        C[j+1] += C[j] * cnt[target[j]-'a'] % MOD;
      }
    }
    return C[n] % MOD;
  }
};
