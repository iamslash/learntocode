/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

// // 1052ms 52.09% 142MB 44.70%
// // hash set
// // O(N^2) O(1)
// class Solution {
//  public:
//   int closestToTarget(vector<int>& A, int tgt) {
//     int ans = INT_MAX;
//     unordered_set<int> sumSet;
//     for (int a : A) {
//       ans = min(ans, abs(a - tgt));
//       unordered_set<int> tmpSet;
//       if (a > tgt) {
//         tmpSet.insert(a);
//         for (int sum : sumSet) {
//           int nextSum = a & sum;
//           ans = min(ans, abs(nextSum - tgt));
//           if (nextSum > tgt)
//             tmpSet.insert(nextSum);
//         }
//       }
//       sumSet = tmpSet;
//     }
//     return ans;
//   }
// };

// tgt: 5
//      i
//   A: 9 12 3 7 15
//         j
//      1001
//      1100
//      0011
//      0111
//      1111

// 292MS 91.78% 71.5MB 79,39%
// skipping
// O(N^2) O(1)
class Solution {
 public:
  int closestToTarget(vector<int>& A, int tgt) {
    int ans = INT_MAX, n = A.size();
    for (int i = 0; i < n && ans; ++i) {
      int k = A[i];
      for (int j = i; j < n && ans; ++j) {
        k &= A[j];
        int diff = abs(k - tgt);
        if (diff >= ans)
          break;
        ans = diff;
        if (k <= tgt)
          break;
      }
    }
    return ans;
  }
};
