/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>

using namespace std;

//      i
// A: 2 4 5 8 10
// B: 4 6 8 9
//    j
//
// a: 2
// b: 0

// 188ms 98.94% 56MB 48.40%
// two pointers
// O(N) O(1)
#define MOD 1000000007
class Solution {
 public:
  int maxSum(vector<int>& A, vector<int>& B) {
    int i = 0, j = 0, n = A.size(), m = B.size();
    int64_t a = 0, b = 0;
    while (i < n || j < m) {
      if (i < n && (j == m || A[i] < B[j])) {
        a += A[i++];
      } else if (j < m && (i == n || A[i] > B[j])) {
        b += B[j++];
      } else {
        a = b = max(a, b) + A[i];
        i++, j++;
      }
    }
    return max(a, b) % MOD;
  }
};
