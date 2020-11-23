/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

//    nums: 1 1 2 2
// freqMap: 1 2
//          2 2
//   freqs: 2 2

// DFS
// 256ms 98.11% 75.2MB 60.33%
class Solution {
 private:
  bool dfs(vector<int>& qtys, int pos, vector<int>& hist) {
    // base
    if (pos == qtys.size())
      return true;
    // recursion
    for (int i = 0; i < hist.size(); ++i) {
      if (hist[i] >= qtys[pos] && (i == 0 || hist[i] != hist[i-1])) {
        hist[i] -= qtys[pos];
        if (dfs(qtys, pos + 1, hist))
          return true;
        hist[i] += qtys[pos];
      }
    }
    return false;
  }
 public:
  bool canDistribute(vector<int>& nums, vector<int>& qtys) {
    unordered_map<int, int> freqMap;
    for (int num : nums)
      freqMap[num]++;
    vector<int> hist;
    for (auto& pr : freqMap)
      hist.push_back(pr.second);
    return dfs(qtys, 0, hist);
  }
};
