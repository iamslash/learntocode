/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // Time Limit Exceeded
// // O(KN) O(1) 
// class Solution {
//  public:
//   int minKBitFlips(std::vector<int>& A, int K) {
//     int n = A.size(), cnt = 0;
//     for (int i = 0; i <= n - K; ++i) {
//       if (A[i] == 1)
//         continue;
//       cnt++;
//       for (int j = 0; j < K; ++j)
//         A[i+j] ^= 1;
//     }
//     for (int i = n - K + 1; i < n; ++i)
//       if (A[i] == 0)
//         return -1;
//     return cnt;
//   }
// };

// If cur is even and A[i] is 0, we need to flip.
// If cur is odd and A[i] is 1, we need to flip.

//   K: 3
//                      i
//   A: 2 0 0 1 2 2 1 0
// cur: 1
// cnt: 3

// 84ms 96.50% 15.8MB 92.34%
// O(N) O(1)
class Solution {
 public:
  int minKBitFlips(vector<int>& A, int K) {
    int n = A.size(), cur = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (i >= K)
        cur -= A[i - K] / 2;
      if ((cur & 1 ^ A[i]) == 0) {
        if (i + K > n)
          return -1;
        A[i] += 2;
        cur++;
        cnt++;
      }
    }
    return cnt;
  }
};

// 36ms 100.00% 15.7MB 93.11%
static const int _ = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
// O(N) O(1)
class Solution {
 public:
  int minKBitFlips(vector<int>& A, int K) {
    int n = A.size(), cur = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (i >= K)
        cur -= A[i - K] / 2;
      if ((cur & 1 ^ A[i]) == 0) {
        if (i + K > n)
          return -1;
        A[i] += 2;
        cur++;
        cnt++;
      }
    }
    return cnt;
  }
};

int main() {
  // std::vector<int> A = {0, 1, 0};
  // int K = 1;
  // std::vector<int> A = {1, 1, 0};
  // int K = 2;
  // std::vector<int> A = {0, 0, 0, 1, 0, 1, 1, 0};
  // int K = 3;
  std::vector<int> A = {0, 0, 1};
  int K = 2;
  
  Solution sln;
  printf("%d\n", sln.minKBitFlips(A, K));
  
  return 0;
}
