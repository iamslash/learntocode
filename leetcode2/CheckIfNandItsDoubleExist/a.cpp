/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// 12m 68.48% 11.5MB 8.93%
// hash map
// O(NlgN) O(N)
class Solution {
 public:
  bool checkIfExist(vector<int>& A) {
    int n = A.size();
    set<int> sst;
    int zeroCnt = 0;
    for (int a : A) {
      if (a == 0)
        zeroCnt++;
      if (zeroCnt >= 2)
        return true;
      sst.insert(a);
    }
    for (int a : A) {
      if (a != 0 && sst.find(a*2) != sst.end()) {
        return true;
      }
    }
    return false;
  }
};
