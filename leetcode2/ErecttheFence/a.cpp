/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

// 104ms 91.47% 21.8MB 62.79%
// https://www.geeksforgeeks.org/convex-hull-monotone-chain-algorithm/
// convex hull monotone chain algorithm
// O(NlgN) O(N)
int64_t cross(const vector<int>& o,
                     const vector<int>& a,
                     const vector<int>& b) {
  return (a[0] - o[0]) * (b[1] - o[1]) -
      (a[1] - o[1]) * (b[0] - o[0]);
}
bool cmp(const vector<int>& a, const vector<int>& b) {
  return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}
bool equ(const vector<int>& a, const vector<int>& b) {
  return a[0] == b[0] && a[1] == b[1];
}
class Solution {
 public:
  vector<vector<int>> outerTrees(vector<vector<int>>& P) {
    int n = P.size(), k = 0;
    if (n <= 3)
      return P;
    vector<vector<int>> ans(2 * n);
    sort(P.begin(), P.end(), cmp);
    // Build lower hull
    for (int i = 0; i < n; ++i) {
      while (k >= 2 &&
             cross(ans[k-2], ans[k-1], P[i]) < 0) {
        --k;
      }
      ans[k++] = P[i];
    }
    // Build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
      while (k >= t && cross(ans[k-2], ans[k-1], P[i]) < 0) {
        --k;
      }
      ans[k++] = P[i];
    }
    ans.resize(k);
    sort(ans.begin(), ans.end(), cmp);
    ans.erase(unique(ans.begin(), ans.end(), equ), ans.end());
    return ans;
  }
};
