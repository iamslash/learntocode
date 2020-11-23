/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 316ms 96.38% 47.9MB 93.57%
// hash set, dfs
class Solution {
 private:
  unordered_set<string> wordSet;
  int minLen = 1;
  bool concatenated(const string& s) {
    // base
    if (wordSet.count(s))
      return true;
    // recursion
    for (int i = minLen; i <= s.size() - minLen; ++i) {
      if (wordSet.count(s.substr(0, i)) > 0 &&
          concatenated(s.substr(i)))
        return true;
    }
    return false;
  }
 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& W) {
    sort(W.begin(), W.end(), [](const string& a, const string& b) {
                               return a.size() < b.size();
                             });
    minLen = max(1, int(W.front().size()));
    vector<string> ans;
    for (int i = 0; i < W.size(); ++i) {
      if (W[i].size() >= minLen * 2 && concatenated(W[i]))
        ans.push_back(W[i]);
      wordSet.insert(W[i]);
    }
    return ans;
  }
};
