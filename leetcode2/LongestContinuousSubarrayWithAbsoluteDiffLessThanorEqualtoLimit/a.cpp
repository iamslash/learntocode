/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <set>
#include <deque>

using namespace std;

// k: 4
//        j
// A: 8 2 4 7
//            j
// s: 4 7 

// // sorted set
// // O(NlgN) O(N)
// class Solution {
//  public:
//   int longestSubarray(vector<int>& A, int k) {
//     int i = 0, j = 0, n = A.size();
//     multiset<int> mst;
//     for (j = 0; j < n; ++j) {
//       mst.insert(A[j]);
//       if (*mst.rbegin() - *mst.begin() > k)
//         mst.erase(mst.find(A[i++]));
//     }
//     return j - i;
//   }
// };

//      k: 4
//             i
//      A: 8 2 4 7
//                 j
//
// maxdeq: 7
// mindeq: 4 7

// 300ms 61.77% 52.2MB 57.59%
// double deque
// O(N) O(N)
class Solution {
 public:
  int longestSubarray(vector<int>& A, int k) {
    deque<int> maxdeq, mindeq;
    int i = 0, j = 0, n = A.size();
    for (j = 0; j < n; ++j) {
      while (maxdeq.size() && A[j] > maxdeq.back()) {
        maxdeq.pop_back();
      }
      while (mindeq.size() && A[j] < mindeq.back()) {
        mindeq.pop_back();
      }
      maxdeq.push_back(A[j]);
      mindeq.push_back(A[j]);
      if (maxdeq.front() - mindeq.front() > k) {
        if (maxdeq.front() == A[i])
          maxdeq.pop_front();
        if (mindeq.front() == A[i])
          mindeq.pop_front();
        ++i;
      }
    }
    return j - i;
  }
};
