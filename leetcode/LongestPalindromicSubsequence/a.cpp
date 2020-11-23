/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// // Brute force
// // O(2^N) O(1)
// class Solution {
//  private:
//   int solve(int l, int r, const std::string& s) {
//     // base
//     if (l == r)
//       return 1;
//     if (l > r)
//       return 0;

//     // recursion
//     // l < r
//     return s[l] == s[r] ?
//         2 + solve(l+1, r-1, s) :
//         std::max(solve(l+1, r, s), solve(l, r-1, s));
//   }
//  public:
//   int longestPalindromeSubseq(const std::string& s) {
//     return solve(0, s.size()-1, s);
//   }
// };

// // dynamic programming recursive way
// // O(n^2) O(N^2)
// class Solution {
//  private:
//   std::vector<std::vector<int>> m_C;
//   std::string m_s;
//   int solve(int l, int r) {
//     // base
//     if (l == r)
//       return 1;
//     if (l > r)
//       return 0;

//     // memoization
//     int& rslt = m_C[l][r];
//     if (r >= 0)
//       return r;

//     // recursion
//     return rslt = m_s[l] == m_s[r] ?
//         2 + solve(l+1, r-1) :
//         std::max(solve(l+1, r), solve(l, r-1));
//   }
//  public:
//   int longestPalindromeSubseq(const std::string& s) {
//     int n = s.size();
//     m_C.resize(n, std::vector<int>(n, -1));
//     return solve(0, n-1);
//   }
// };

// // dynamic programming iterative way
// // O(n^2) O(N^2)
// class Solution {
//  public:
//   int longestPalindromeSubseq(const std::string& s) {
//     int n = s.size();
//     if (n < 2)
//       return n;    // C[length][start index]
//     std::vector<std::vector<int>> C(n+1, std::vector<int>(n, 0));
//     for (int j = 0; j < n; ++j)
//       C[1][j] = 1;
//     for (int i = 2; i <= n; ++i) {
//       for (int j = 0; j < n-i+1; ++j) {
//         C[i][j] = s[j] == s[j+i-1] ?
//             2 + C[i-2][j+1] :
//             std::max(C[i-1][j], C[i-1][j+1]);
//       }
//     }
//     return C[n][0];    
//   }
// };

// len: 3
// tmp: 3
//              i
//      j
//   s: b b b a b
//   C: 4 3 3 1 1

// 36ms 93.57%
// dynamic programming iterative way optimizing space complexity
// O(N^2) O(N)
class Solution {
 public:
  int longestPalindromeSubseq(const std::string& s) {
    int n = s.size();
    // C[i] : longest palindrom subseq start from i
    std::vector<int> C(n, 1);
    int rslt = 0;
    for (int i = 1; i < n; ++i) {
      int len = 0;
      for (int j = i - 1; j >= 0; --j) {
        int tmp = C[j];
        if (s[j] == s[i])
          C[j] = len + 2;
        len = std::max(len, tmp);
      }
    }
    for (int i : C)
      rslt = std::max(rslt, i);
    return rslt;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.longestPalindromeSubseq("bbbab"));
  
  return 0;
}
