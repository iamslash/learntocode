/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// K: 1
// A: 4 . . 7 . 9 10
//          h      
//          l

// K: 4
// A: 1 2 . 4
//    l m   h

// 84ms 82.63% 12MB 100.00%
// binary search
// O(lgN) O(1)
class Solution {
 public:
  int missingElement(std::vector<int>& A, int k) {
    int l = 0, m, h = A.size() - 1;
    while (l < h) {
      m = (l + h) / 2;
      if (k <= A[m] - m - A[0])
        h = m;
      else
        l = m + 1;
    }
    if (A[l] - l - A[0] < k)
      return A[l] + k - (A[l] - l - A[0]);
    return A[0] + l + k - 1;
  }
};

int main() {
  return 0;
}
