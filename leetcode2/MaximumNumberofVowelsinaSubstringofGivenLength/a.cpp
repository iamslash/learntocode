/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// k: 3
//    i
// s: a b c i i i d e f
//

// i       j
// t r y h a r d
//


// 52ms 98.69% 10.1MB 37.17%
// sliding window
// O(N) O(1)
class Solution {
 public:
  int maxVowels(string s, int k) {
    int vowels[26] = {1, 0, 0, 0, 1,
                      0, 0, 0, 1, 0,
                      0, 0, 0, 0, 1,
                      0, 0, 0, 0, 0,
                      1, 0, 0, 0, 0, 0};
    int n = s.size(), glbmax = 0, locmax = 0;
    for (int j = 0; j < n; ++j) {
      int i = j - k;
      // consider left most
      if (i >= 0) {
        locmax -= vowels[s[i]-'a'];
      }
      // consider right most
      locmax += vowels[s[j]-'a'];
      glbmax = max(glbmax, locmax);
      // printf("locmax:%d, glbmax:%d\n", locmax, glbmax);
    }
    return glbmax;
  }
};
