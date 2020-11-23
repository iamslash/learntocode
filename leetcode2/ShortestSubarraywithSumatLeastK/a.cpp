/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

//   A: 2 -1 2
//   K: 3
//   A: 2  1 3
//           i
// deq: 0 1
// ans: 3

// 264ms 70.86% 60.2MB 94.46%
// sliding window
// O(N) O(N)
class Solution {
 public:
  int shortestSubarray(vector<int>& A, int K) {
    int n = A.size();
    int ans = A.size() + 1;
    deque<int> deq;
    for (int i = 0; i < n; ++i) {
      if (i > 0)
        A[i] += A[i-1];
      if (A[i] >= K)
        ans = min(ans, i + 1);
      while (deq.size() > 0 && A[i] - A[deq.front()] >= K) {
        ans = min(ans, i - deq.front());
        deq.pop_front();
      }
      while (deq.size() > 0 && A[i] <= A[deq.back()])
        deq.pop_back();
      deq.push_back(i);
    }
    return ans > n ? -1 : ans;
  }
};
