/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 84ms 60.00% 30.6MB 40.00%
// hash map
// O(N) O(1)
class Solution {
 public:
  int countConsistentStrings(string allowed,
                             vector<string>& words) {
    vector<int> freqs(26);
    for (int i = 0; i < allowed.length(); ++i) {
      freqs[allowed[i]-'a']++;
    }
    int cnt = 0;
    for (string& word : words) {
      bool bConsistent = true;
      for (char c : word) {
        if (freqs[c-'a'] == 0) {
          bConsistent = false;
          break;
        }
      }
      if (bConsistent) {
        cnt++;
      }      
    }
    return cnt;
  }
};
