/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

//   A: 10  2 -10  5 20
//   k: 2 
//   A: 10 12   2 17 37
//                    i
//   q: 37
// ans: 37


//   A: 10 -2 -10 -5 20
//   k: 2
//   A: 10  8   0  3 23
//                      i
//   q: 23
// ans: 23

// 260ms 37.33% 39.5MB 88.73%
// deque
// O(N) O(N)
class Solution {
 public:
  int constrainedSubsetSum(vector<int>& A, int k) {
    deque<int> q;
    int ans = A[0];
    int n = A.size();
    for (int i = 0; i < n; i++) {
      if (q.size() > 0)
        A[i] += q.front();
      ans = max(ans, A[i]);
      while (q.size() > 0 && A[i] > q.back())
        q.pop_back();
      if (A[i] > 0)
        q.push_back(A[i]);
      if (i >= k && q.size() > 0 && q.front() == A[i-k])
        q.pop_front();
    }
    return ans;
  }
};
