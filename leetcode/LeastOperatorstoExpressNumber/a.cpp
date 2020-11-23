/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <limits>
#include <cstdint>
#include <algorithm>

// // 48ms 21.05%
// // O(log_{X}^{T}) O(lgT)
// class Solution {
//  public:
//   int leastOpsExpressTarget(int X, int T) {
//     // printf("%d %d\n", X, T);
//     if (X == T)
//       return 0;
//     // min(x/x + x/x + ... + x/x, x - x/x + x/x + ... + x/x)
//     // x=3, t=2
//     // 2 = 3/3 + 3/3 or 2 = 3 - 3/3
//     if (X > T)
//       return std::min(T*2-1, (X-T)*2);
//     // x < T
//     int64_t P = X;  // product of x
//     int K = 0;         // times of x
//     while (P < T) {
//       K++;
//       P *= X;
//     }
//     if (P == T)
//       return K;
//     int sub = std::numeric_limits<int>::max();
//     if (P-T < T)
//       sub = leastOpsExpressTarget(X, P-T) + K;
//     int add = leastOpsExpressTarget(X, T-(P/X)) + K-1;
//     return std::min(add, sub) + 1;
//   }
// };

class Soilution {
 public:
  int leastOpsExpressTarget(int X, int T) {
    
  }
};

int main() {
  int x = 3, T = 19;
  Solution sln;
  printf("%d\n", sln.leastOpsExpressTarget(x, T));  
  return 0;
}
