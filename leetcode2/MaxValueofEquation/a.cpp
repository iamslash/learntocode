/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <deque>
#include <cstdlib>

using namespace std;

// // Time Limit Exceeded
// // brute force
// // O(N^2) O(1)
// class Solution {
//  public:
//   int findMaxValueOfEquation(vector<vector<int>>& P, int k) {
//     int ans = INT_MIN, n = P.size(), l = 0, r = 0;
//     for (int i = 0; i < n; ++i) {
//       for (int j = i+1; j < n && P[j][0] - P[i][0] <= k; ++j) {
//         ans = max(ans, P[i][1] + P[j][1] + P[j][0] - P[i][0]);
//       }
//     }
//     return ans;
//   }
// };

// 696ms 65.91% 89.7MB 93.75%
// monotonic decreasing deque
// O(N) O(N)
class Solution {
 public:
  int findMaxValueOfEquation(vector<vector<int>>& P, int k) {
    deque<int> D;
    int ans = INT_MIN, n = P.size();
    for (int i = 0; i < n; ++i) {
      while (D.size() && P[i][0] - P[D.front()][0] > k)
        D.pop_front();
      if (D.size())
        ans = max(ans, P[D.front()][1] - P[D.front()][0] + P[i][1] + P[i][0]);
      while (D.size() && P[D.back()][1] - P[D.back()][0] < P[i][1] - P[i][0])
        D.pop_back();
      D.push_back(i);
    }
    return ans;
  }
};
