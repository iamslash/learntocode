/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// // 692ms 49.81% 24.2MB 17.08%
// // partial sum
// // O(N^2) O(N)
// #define MOD 1000000007
// class Solution {
//  public:
//   int rangeSum(vector<int>& nums, int n, int left, int right) {
//     vector<int> ps(n+1, 0);
//     for (int i = 0; i < n; ++i) {
//       ps[i+1] = (ps[i] + nums[i]) % MOD;
//     }
//     vector<int> A;
//     for (int i = 0; i < n; ++i) {
//       for (int j = i; j < n; ++j) {
//         A.push_back(ps[j+1]-ps[i]);
//       }        
//     }
//     sort(A.begin(), A.end());
//     int ans = 0;
//     for (int i = left; i <= right; ++i) {
//       ans = (ans + A[i-1]) % MOD;
//     }
//     return ans;
//   }
// }; 

// 384ms 84.06% 7.9MB 96.85%
// priority queue
// O(NlgN) O(N)
#define MOD 1000000007
class Solution {
 public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    for (int i = 0; i < n; ++i)
      pq.push({nums[i], i+1});
    int ans = 0;
    for (int i = 1; i <= right; ++i) {
      auto pr = pq.top(); pq.pop();
      if (i >= left)
        ans = (ans + pr.first) % MOD;
      if (pr.second < n) {
        pr.first += nums[pr.second++];
        pq.push(pr);
      }
    }
    return ans;
  }
}; 

