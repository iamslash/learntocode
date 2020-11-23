/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//      A: 1 1 2 2 1 1
// idxMap: {{1:[0,1,4,5], {2:[2,3]}}
//
//  query: 0,5
// thresh: 4

// 1060ms 5.78% 65.7MB 87.11%
// binary search
// O(NlgN) O(N)
class MajorityChecker {
 private:
  unordered_map<int, vector<int>> idxMap;
 public:
  MajorityChecker(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
      idxMap[A[i]].push_back(i);
    }
  }    
  int query(int left, int right, int threshold) {
    for (auto& pr : idxMap) {
      auto& idxs = pr.second;
      if (idxs.size() < threshold)
        continue;
      auto it = lower_bound(idxs.begin(), idxs.end(), left);
      auto jt = upper_bound(idxs.begin(), idxs.end(), right);
      if (jt - it >= threshold)
        return pr.first;
    }
    return -1;
  }
};
