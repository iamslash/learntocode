/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// // Time Limit Exceeded
// // brute force
// // O(N^2) O(N^2)
// class Solution {
//  public:
//   int smallestDistancePair(vector<int>& A, int k) {
//     int n = A.size();
//     vector<int> ans;
//     for (int i = 0; i < n - 1; ++i) {
//       for (int j = i+1; j < n; ++j) {
//         ans.push_back(abs(A[i] - A[j]));
//       }
//     }
//     sort(ans.begin(), ans.end());
//     return ans[k];
//   }
// };

//    i
// A: 1 1 3
//        j
// 

// // Time Limit Exceeded
// // binary search
// // O(NlgN) O(1)
// class Solution {
//  private:
//   int count(vector<int>& A, int dist) {
//     int n = A.size(), ans = 0;
//     for (int i = 0; i < n; ++i) {
//       int j = i + 1;
//       while (j < n && A[j] - A[i] <= dist)
//         j++;
//       ans += j - i - 1;
//     }
//     return ans;
//   }
//  public:
//   int smallestDistancePair(vector<int>& A, int k) {
//     int n = A.size();
//     sort(A.begin(), A.end());

//     int lo = INT_MAX;
//     for (int i = 1; i < n; ++i) {
//       lo = min(lo, A[i] - A[i-1]);
//     }
//     int hi = A[n-1] - A[0];
//     while (lo < hi) {
//       int mi = lo + (hi - lo) / 2;
//       if (count(A, mi) < k) {
//         lo = mi + 1;
//       } else {
//         hi = mi;
//       }
//     }
//     return lo;
//   }
// };

// 24ms 92.38% 10.1MB 64.20%
// binary search
// O(NlgN) O(1)
class Solution {
 private:
  int count(vector<int>& A, int dist) {
    int n = A.size(), ans = 0;
    int l = 0, r = 1;
    while (r < n) {
      if (A[r] - A[l] <= dist) {
        ans += r - l;
        ++r;
      } else {
        ++l;
      }
    }
    return ans;
  }
 public:
  int smallestDistancePair(vector<int>& A, int k) {
    int n = A.size();
    sort(A.begin(), A.end());

    int lo = INT_MAX;
    for (int i = 1; i < n; ++i) {
      lo = min(lo, A[i] - A[i-1]);
    }
    int hi = A[n-1] - A[0];
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (count(A, mi) < k) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return lo;
  }
};
