/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// [2,2,2,2,2,2]
// [5,1,6,4,3,2]
//            i
// dic: 2
// ans: 2

// 1 2 3 4 6
// 6 6 6 6 5
//         i

// [2,1,1,3,2,1,2,2,1]
// [3,2,3,1,3,2,3,3,2]
//    i

// brute force
// O(N) O(1)
class Solution {
 public:
  int minDominoRotations(std::vector<int>& A, std::vector<int>& B) {
    int ans = 0, n = A.size(), dice = 0;
    for (int i = 1; i < n; ++i) {
      if (dice > 0) {
        if (dice != A[i] && dice != B[i])
          return -1;
        if ((dice != A[i-1] && dice == A[i]) ||
            (dice != B[i-1] && dice == B[i]))
          std::swap(A[i], B[i]), ++ans;
      } else {
        if (A[i-1] != A[i] && A[i-1] != B[i] &&
            B[i-1] != B[i] && B[i-1] != A[i])
          return -1;
        if (A[i-1] == A[i] && B[i-1] == B[i])
          continue;
        if (A[i-1] == B[i] && B[i-1] != A[i]) {
          dice = B[i];
          std::swap(A[i], B[i]);
          ++ans;
        } else if (B[i-1] == A[i] && A[i-1] != B[i]) {
          dice = A[i];
          std::swap(A[i], B[i]);
          ++ans;
        } else if (A[i-1] == A[i] && B[i-1] != B[i]) {
          dice = A[i];
        } else if (B[i-1] == B[i] && A[i-1] != A[i]) {
          dice = B[i];
        }        
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
