/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <set>
#include <vector>
#include <map>

using namespace std;

// 28ms 42.71% 10.7MB 33.29%
// sorted set
// O(NlgN) O(N)
class Solution {
 private:
  int ones(vector<int>& A) {
    int ans = 0;
    for (int i = 0; i < A.size(); ++i) {
      if (A[i])
        ans++;
      else
        break;
    }
    return ans;
  }
 public:
  vector<int> kWeakestRows(vector<vector<int>>& M, int k) {
    set<pair<int,int>> cnts;
    for (int i = 0; i < M.size(); ++i) {      
      cnts.insert({ones(M[i]), i});
    }
    vector<int> ans;
    for (auto pa : cnts) {
      ans.push_back(pa.second);
    }
    return ans;
  }
};
