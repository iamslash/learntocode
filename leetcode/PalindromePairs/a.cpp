/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

// 296ms 38.07%
// string
// O(WS^2) O(WS)
class Solution {
 private:
  bool isPalindrome(const string& a, int s, int e) {
    while (s < e) {
      if (a[s++] != a[e--]) 
        return false;
    }
    return true;
  }
 public:
  vector<vector<int>> palindromePairs(vector<string>& W) {
    vector<vector<int>> rslt;
    unordered_map<string, int> D;
    for (int i = 0; i < W.size(); i++) {
      D[W[i]] = i;
    }
    for (int i = 0; i < W.size(); i++) {
      for (int j = 0; j <= W[i].size(); j++) {
        // suffix
        if (isPalindrome(W[i], j, W[i].size()-1)) {
          string suffix = W[i].substr(0, j);
          reverse(suffix.begin(), suffix.end());
          if (D.count(suffix) > 0 && i != D[suffix]) {
            rslt.push_back({i, D[suffix]});
          }
        }
        // prefix
        if (j > 0 && isPalindrome(W[i], 0, j-1)) {
          string prefix = W[i].substr(j);
          reverse(prefix.begin(), prefix.end());
          if (D.count(prefix) > 0 && i != D[prefix]) {
            rslt.push_back({D[prefix], i});
          }
        }
      }
    }
    return rslt;
  }
};

int main() {

  std::vector<std::string> W = {{"abcd"},{"dcba"},{"lls"},{"s"},{"sssll"}};
  Solution sln;
  auto rslt = sln.palindromePairs(W);
  return 0;
}
