/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//    i
// A: 1 3 2 3 1
//      j

// i < j, A[i] > 2*A[j]
// i < j, A[i]/2.0 <= A[j]
//
//    i
// A: 4 6 8    1 2 3
//             j
// 

// // Time Limit Excceded
// // merge sort
// // O(N^2lgN) O(lgN)
// class Solution {
//  private:
//   int mergeSort(vector<int>& A, int s, int e) {
//     if (s >= e)
//       return 0;
//     int m = s + (e - s) / 2;
//     int cnt = mergeSort(A, s, m) + mergeSort(A, m+1, e);
//     for (int i = s, j = m + 1; i <= m; ++i) {
//       while (j <= e && A[i] / 2.0 > A[j])
//         ++j;
//       cnt += j - (m + 1);
      
//     }
//     sort(A.begin() + s, A.begin() + e + 1);
//     return cnt;
//   }
//  public:
//   int reversePairs(vector<int>& A) {
//     return mergeSort(A, 0, A.size() - 1);
//   }
// };

// // Time Limit Excceded
// // merge sort
// // O(NlgN) O(lgN)
// class Solution {
//  private:
//   void _mergeSort(vector<int>& A, int s, int m, int e) {
//     vector<int> B(A.size());
//     for (int i = s; i <= e; ++i)
//       B[i] = A[i];
//     int j = s;
//     int k = m + 1;
//     int i = s;
//     while (j <= m || k <= e) {
//       if (j > m || (k <= e && B[j] >= B[k])) {
//         A[i++] = B[k++];
//       } else {
//         A[i++] = B[j++];
//       }
//     }
//   }
//   int mergeSort(vector<int>& A, int s, int e) {
//     if (s >= e)
//       return 0;
//     int m = s + (e - s) / 2;
//     int cnt = mergeSort(A, s, m) + mergeSort(A, m+1, e);
//     for (int i = s, j = m + 1; i <= m; ++i) {
//       while (j <= e && A[i] / 2.0 > A[j])
//         ++j;
//       cnt += j - (m + 1);
      
//     }
//     _mergeSort(A, s, m, e);
//     return cnt;
//   }
//  public:
//   int reversePairs(vector<int>& A) {
//     return mergeSort(A, 0, A.size() - 1);
//   }
// };

// // 1116ms 20.23% 109.4MB 41.85%
// // merge sort
// O(NlgN) O(lgN)
// class Solution {
//  private:
//   int mergeSort(vector<int>::iterator beg, vector<int>::iterator end) {
//     if (end - beg <= 1)
//       return 0;
//     auto mid = beg + (end - beg) / 2;
//     int cnt = mergeSort(beg, mid) + mergeSort(mid, end);
//     for (auto i = beg, j = mid; i != mid; ++i) {
//       while (j != end && (*i) > 2L * (*j))
//         ++j;
//       cnt += j - mid;
//     }
//     inplace_merge(beg, mid, end);
//     return cnt;                                                
//   }
//  public:
//   int reversePairs(vector<int>& A) {
//     return mergeSort(A.begin(), A.end());
//   }
// };

// 688ms 45.26% 109.3MB 42.70%
// merge sort
// O(NlgN) O(lgN)
class Solution {
 private:
  int mergeSort(vector<int>::iterator beg, vector<int>::iterator end) {
    if (end - beg <= 1)
      return 0;
    auto mid = beg + (end - beg) / 2;
    int cnt = mergeSort(beg, mid) + mergeSort(mid, end);
    for (auto i = beg, j = mid; i != mid; ++i) {
      while (j != end && (*i) > 2L * (*j))
        ++j;
      cnt += j - mid;
    }
    inplace_merge(beg, mid, end);
    return cnt;                                                
  }
 public:
  int reversePairs(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return mergeSort(A.begin(), A.end());
  }
};
