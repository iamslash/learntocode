/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// boxTypes: 5,10 2,5 4,7 3,9
// boxTypes: 2,5 3,9 4,7 5,10
//           5,10 3,9 4,7 2,5
//           50 27 14


// 80ms 33.33% 16.3MB 66.67%
// sort
// O(NlgN) O(1)
class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](vector<int>& a,
            vector<int>& b){
           return a[1] > b[1];
         });
    int unitCnt = 0, n = boxTypes.size();
    for (int i = 0; i < n; ++i) {
      int boxCnt = min(boxTypes[i][0], truckSize);
      unitCnt += boxCnt * boxTypes[i][1];
      truckSize -= boxCnt;
      if (truckSize <= 0)
        break;
    }
    return unitCnt;
  }
};
