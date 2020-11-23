/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 0 0 1
// 1 1 0
// 1 0 0

//               i
// postZeroCnts: 2 0 1
//                 k
// 

// 152ms 59.56% 26MB 25.23%
// greedy algorithm
// O(N^2) O(N)
class Solution {
 public:
  int minSwaps(vector<vector<int>>& G) {
    int n = G.size();
    vector<int> postZeroCnts(n);
    for (int y = 0; y < n; ++y) {
      int cnt = 0;
      for(int x = n-1; x >= 0 && G[y][x] == 0; --x) {
        cnt++;
      }
      postZeroCnts[y] = cnt;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int k = i;
      int need = n - 1 - i;
      while (k < n && postZeroCnts[k] < need) {
        ++k;
      }
      if (k == n) {
        return -1;
      }
      ans += k - i;
      while (k > i) {
        swap(postZeroCnts[k], postZeroCnts[k-1]);
        k--;
      }
    }
    return ans;
  }
};
