/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// [1,3],[1,4],[3,5],[2,5]

// 96ms 94.90% 17.6MB 79.08%
// sort
// O(NlgN) O(1)
class Solution {
 public:
  int intersectionSizeTwo(vector<vector<int>>& I) {
    sort(I.begin(), I.end(), [](const vector<int>& a,
                                const vector<int>& b) {
                               if (a[1] == b[1])
                                 return a[0] > b[0];
                               return a[1] < b[1];
                             });
    int left = I[0][1] - 1, right = I[0][1];
    int n = I.size(), ans = 2;    
    for (int i = 1; i < n; ++i) {
      auto& interval = I[i];
      if (left < interval[0] && interval[0] <= right) {
        ans++;
        left = right;
        right = interval[1];
      } else if (right < interval[0]) {
        ans += 2;
        left = interval[1] - 1;
        right = interval[1];
      }
    }
    return ans;
  }
};
