/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// A: 1 0 0 0 0
// B:     1 0 1

// C:   1 2 1 2  
// A: 1 1 1 1 1
// B: 1 0 1
// R: 0 0 0 0 1-1     


// A: 1
// B: 1
// C: 0 1 1

// // 12ms 77.54% 9MB 100.00%
// // O(N) O(N)
// class Solution {
//  public:
//   std::vector<int> addNegabinary(
//       std::vector<int>& A,
//       std::vector<int>& B) {
//     int n = std::max(A.size(), B.size()) + 2;
//     std::vector<int> C(n, 0);
//     std::reverse(A.begin(), A.end());
//     std::reverse(B.begin(), B.end());

//     for (int i = 0; i < n; ++i) {
//       int c = C[i];
//       int a = i < A.size() ? A[i] : 0;
//       int b = i < B.size() ? B[i] : 0;
//       int s = c + a + b;

//       C[i] = s % 2;
//       if (s == 2 || s == 3) {
//         if (i+1 < n)
//           C[i+1] += 1;
//         if (i+2 < n)
//           C[i+2] += 1;
//       } else if (s == 4) {
//         if (i+2 < n)
//           C[i+2] += 1;
//       }
//     }

//     while (C.size() > 1 && C.back() <= 0)
//       C.pop_back();
//     std::reverse(C.begin(), C.end());
//     return C;
//   }
// };

// 12ms 77.54% 9MB 100.00%
// O(N) O(N)
class Solution {
 public:
  std::vector<int> addNegabinary(
      std::vector<int>& A,
      std::vector<int>& B) {
    int n = std::max(A.size(), B.size()) + 2;
    std::vector<int> C(n, 0);

    int i = 0;
    auto ri = A.rbegin();
    auto rj = B.rbegin();
    while (i < n) {
      int c = C[i];
      int a = ri != A.rend() ? *ri : 0;
      int b = rj != B.rend() ? *rj : 0;
      int s = c + a + b;

      C[i] = s % 2;
      if (s == 2 || s == 3) {
        if (i+1 < n)
          C[i+1] += 1;
        if (i+2 < n)
          C[i+2] += 1;
      } else if (s == 4) {
        if (i+2 < n)
          C[i+2] += 1;
      }
      
      ++i;
      if (ri != A.rend())
        ++ri;
      if (rj != B.rend())
        ++rj;
    }

    while (C.size() > 1 && C.back() <= 0)
      C.pop_back();
    std::reverse(C.begin(), C.end());
    return C;
  }
};


int main() {
  return 0;
}
