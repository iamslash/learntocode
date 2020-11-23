/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 4ms 61.03% 8.6MB 30.99%
class Solution {
 public:
  vector<int> createTargetArray(vector<int>& vals, vector<int>& idxs) {
    vector<int> ans;
    int n = vals.size();
    for (int i = 0; i < n; ++i) {
      ans.insert(ans.begin() + idxs[i], vals[i]);
    }
    return ans;
  }
};
