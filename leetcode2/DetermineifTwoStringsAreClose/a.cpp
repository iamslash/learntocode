/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 320ms 34.82% 21.2MB 18.80%
// hash map
// O(NlgN) O(1)
class Solution {
 public:
  bool closeStrings(string s, string t) {
    if (s.size() != t.size())
      return false;
    map<int, int> freqSMap;
    map<int, int> freqTMap;
    vector<int> freqS(26);
    vector<int> freqT(26);
    for (char c : s) {
      freqSMap[c-'a']++;
      freqS[c-'a']++;
    }
    for (char c : t) {
      freqTMap[c-'a']++;
      freqT[c-'a']++;
    }
    for (auto& pr : freqSMap) {
      if (freqTMap.count(pr.first) == 0) {
        return false;
      }
    }
    sort(freqS.begin(), freqS.end());
    sort(freqT.begin(), freqT.end());
    return freqS == freqT;
  }
};
