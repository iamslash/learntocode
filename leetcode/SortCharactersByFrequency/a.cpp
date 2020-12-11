/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

// 80ms 17.14% 8.3MB 95.55%
// sort, hash map
// O(NlgN) O(N)
class Solution {
 public:
  string frequencySort(string s) {
    int freqs[256] = {0,};
    for (char c : s) {
      ++freqs[c];
    }
    sort(s.begin(), s.end(), [&](char a, char b) {
                               if (freqs[a] == freqs[b])
                                 return a < b;
                               return freqs[a] > freqs[b];
                            });
    return s;
  }
};

//
// 12ms 95.59% 8.8MB 71.89%
class Solution {
 public:  
  string frequencySort(string s) {
    string ans;
    vector<int> freqs(256);
    for (char c : s) {
      ++freqs[c];
    }
    int maxidx = 0, maxval = INT_MIN;
    for (int i = 0; i < s.length(); ++i) {
      for (int j = 0; j < 256; ++j) {
        if (maxval < freqs[j]) {
          maxval = freqs[j];
          maxidx = j;
        }
      }
      if (maxval == 0) {
        return ans;
      } else {
        for (int k = 0; k < maxval; ++k) {
          ans.push_back(char(maxidx));
        }
        freqs[maxidx] = 0;
        maxval = INT_MIN;
      }
    }
    return ans;
  }
};
