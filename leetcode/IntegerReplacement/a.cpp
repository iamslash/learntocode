/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// recursive way
// 0ms 100.00%
class Solution {
 private:
  std::unordered_map<int, int> m_C;
  int solve(int n) {
    // base
    if (n == 1)
      return 0;

    // memoization
    if (m_C.count(n) > 0)
      return m_C[n];
    int& r = m_C[n];

    // recursion
    if (n % 2 == 0)
      r = solve(n/2) + 1;
    else
      r = std::min(solve(n/2), solve(n/2+1)) + 2;
    return r;
  }
 public:
  int integerReplacement(int n) {
    m_C[0] = 0;
    m_C[1] = 0;
    return solve(n);
  }
};


// // iterative way
// class Solution {
//  public:
//   int integerReplacement(int n) {
//     std::unordered_map<int, int> ump;
//     ump[0] = 0;
//     ump[1] = 0;
//     // C[0] = C[1] = 0;
//     for (int i = 2; i <= n; ++i) {
//       if (i % 2 == 0)
//         C[i] = 1 + C[i/2];
//       else
//         C[i] = 2 + std::min(C[(i-1)/2], C[(i+1)/2]);
//     }    
//     return C[n];
//   }
// };

int main() {
  Solution sln;

  printf("%d\n", sln.integerReplacement(1));
  printf("%d\n", sln.integerReplacement(8));
  printf("%d\n", sln.integerReplacement(7));
  printf("%d\n", sln.integerReplacement(65535));
  printf("%d\n", sln.integerReplacement(100000000));
  printf("%d\n", sln.integerReplacement(2147483647));  
  
  return 0;
}
