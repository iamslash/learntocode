/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

//         i
//      s: 8 4 5 3 2
//      t: 3 4 8 5 2
//         c
//
// idxVec: 2 3 4 5 8
//        ----------
//         4 3 1 2 0
//
// posVec:

// 92ms 99.28% 23.1MB 23.46%
// hash map, greedy
// O(N) O(N)
class Solution {
 public:
  bool isTransformable(string s, string t) {
    vector<vector<int>> idxVec(10);
    vector<int> posVec(10);
    for (int i = 0; i < s.size(); ++i) {
      idxVec[s[i] - '0'].push_back(i);
    }
    for (char c : t) {
      int j = c - '0';
      if (posVec[j] >= idxVec[j].size())
        return false;
      for (int i = 0; i < j; ++i) {
        if (posVec[i] < idxVec[i].size() && idxVec[i][posVec[i]] < idxVec[j][posVec[j]])
          return false;
      }
      ++posVec[j];
    }
    return true;
  }
};
