/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// // 20ms 64.36%
// // binary search
// // O(lgN) O(1)
// class Solution {
//  public:
//   int findSpecialInteger(vector<int>& A) {
//     int n = A.size();
//     vector<int> candidates = {A[n/4], A[n/2], A[n*3/4]};
//     for (int cand : candidates) {
//       auto i = lower_bound(A.begin(), A.end(), cand);
//       auto j = upper_bound(A.begin(), A.end(), cand);
//       int diff = distance(i, j);
//       if (diff * 4 > n)
//         return cand;
//     }
//     return -1;
//   }
// };

// 28ms 44.77% 12.4MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
 public:
  int findSpecialInteger(const vector<int>& A) {
    int cnt = 0;
    for (int i = 0; i < A.size() - 1; ++i) {
      if (A[i] == A[i+1]) {
        cnt++;
      } else {
        cnt = 1;
      }
      if (cnt > (A.size()/4))
        return A[i];    }
    return 1;
  }
};

