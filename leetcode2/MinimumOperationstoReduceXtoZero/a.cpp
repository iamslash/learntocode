/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

// Longest Sub Array with sum "sum - x"

// x: 5
// A: 1 1 4 2 3

// 720ms 49.48% 153.8MB 34.91%
// prefix sum
// O(N) O(N)
class Solution {
 public:
  int minOperations(vector<int>& A, int x) {
    int n = A.size();
    int tgt = -x;
    for (int a : A)
      tgt += a;
    if (tgt == 0)
      return A.size();
    unordered_map<int, int> ump;
    ump[0] = -1;
    int sum = 0, ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
      sum += A[i];
      if (ump.count(sum - tgt)) {
        ans = max(ans, i - ump[sum - tgt]);
      }
      ump[sum] = i;
    }
    return ans == INT_MIN ? -1 : n - ans;
  }
};

//   A: 1 1 4 2 3
// tgt: 6
//            i
//  ps: 0 1 2 6 8 11
//      h

//   A: 1 1
// tgt: -1
//          i
//  ps: 0 1 2 
//        h
// ans: -

// 316ms 86.85% 103.1MB 67.34%
// prefix sum
// O(N) O(N)
class Solution {
 public:
  int minOperations(vector<int>& A, int x) {
    int n = A.size();
    vector<int> ps(n+1);
    for (int i = 1; i <= n; ++i) {
      ps[i] = ps[i-1] + A[i-1];
    }
    int ans = -1, tgt = ps.back() - x, head = 0;
    for (int i = 1; i <= n; ++i) {
      while (head < i &&
             ps[i] - ps[head] > tgt)
        head++;
      if (ps[i] - ps[head] == tgt)
        ans = max(ans, i - head);
    }
    if (ans < 0)
      return -1;
    return n - ans;
  }
};
