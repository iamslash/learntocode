/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

//
// adjPairs: [2,1],[3,4],[3,2]]
//   adjMap: 3 4 1 2 
//           2 3 2 1 
//           4     3
//      ans: 1 2 3 4
//             p t

using namespace std;

class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjPairs) {
    unordered_map<int, vector<int>> adjMap;
    for (auto& u : adjPairs) {
      adjMap[u[0]].push_back(u[1]);
      adjMap[u[1]].push_back(u[0]);
    }
    vector<int> ans;
    for (auto& u : adjMap) {
      if (u.second.size() == 1) {
        ans.push_back(u.first);
        ans.push_back(u.second[0]);
        break;
      }
    }
    while (ans.size() <= adjPairs.size()) {
      int tail = ans.back();
      int prev = ans[ans.size() - 2];
      auto& next = adjMap[tail];
      if (next[0] != prev) {
        ans.push_back(next[0]);
      } else {
        ans.push_back(next[1]);
      }
    }
    return ans;
  }
};
