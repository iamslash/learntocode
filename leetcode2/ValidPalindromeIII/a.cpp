/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// // 36ms 50.81% 16.7MB 17.57%
// // dynamic programming iterative way
// // O(n^2) O(N^2)
// class Solution {
//  private:
//   int longestPalindromeSubseq(const string& s) {
//     int n = s.size();
//     if (n < 2)
//       return n;    // C[length][start index]
//     vector<vector<int>> C(n+1, vector<int>(n, 0));
//     for (int j = 0; j < n; ++j)
//       C[1][j] = 1;
//     for (int i = 2; i <= n; ++i) {
//       for (int j = 0; j < n-i+1; ++j) {
//         C[i][j] = s[j] == s[j+i-1] ?
//             2 + C[i-2][j+1] :
//             max(C[i-1][j], C[i-1][j+1]);
//       }
//     }
//     return C[n][0];    
//   }
//  public:
//   bool isValidPalindrome(string s, int k) {
//     return s.size() - longestPalindromeSubseq(s) <= k; 
//   }
// };

// 32ms 60.19% 6.3MB 100.00%
// dynamic programming iterative way
// O(n^2) O(N^2)
class Solution {
 private:
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
 public:
  bool isValidPalindrome(string s, int k) {
    return s.size() - longestPalindromeSubseq(s) <= k; 
  }
};
