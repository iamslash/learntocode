/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// 576ms 87.02% 109.6MB 74.07%
// hash map, binary search
// O(NlgN) O(N)
class Solution {
 public:
  vector<int> avoidFlood(vector<int>& R) {
    int n = R.size();
    unordered_map<int, int> lakeMap;
    vector<int> ans(n, -1);
    set<int> zeroIdxSet;
    for (int i = 0; i < n; ++i) {
      if (R[i] == 0) {
        zeroIdxSet.insert(i);
        ans[i] = 1;
      } else {
        if (lakeMap.count(R[i])) {
          int last = lakeMap[R[i]];
          auto it = zeroIdxSet.upper_bound(last);
          if (it == zeroIdxSet.end())
            return {};
          ans[*it] = R[i];
          zeroIdxSet.erase(it);
        }
        lakeMap[R[i]] = i;
      }
    }
    return ans;
  }
};
