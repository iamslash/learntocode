/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

//
// adjPairs: [2,1],[3,4],[3,2]]
//   adjMap: 1 2 3 4 
//           2 1 2 3
//             3 4
//      ans: 1 2 3 4
//               p t

using namespace std;

// 516ms 86.13% 105.6MB 85.49%
// greedy
// O(E) O(E)
class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& E) {
    unordered_map<int, vector<int>> adjMap;
    for (auto& e : E) {
      adjMap[e[0]].push_back(e[1]);
      adjMap[e[1]].push_back(e[0]);
    }
    vector<int> ans;
    for (auto& u : adjMap) {
      if (u.second.size() == 1) {
        ans.push_back(u.first);
        ans.push_back(u.second[0]);
        break;
      }
    }
    while (ans.size() <= E.size()) {
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
