/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <set>
#include <vector>

using namespace std;

// // Time Limit Exceeded
// // DFS
// // O(N2^N) O(N)
// class Solution {
//  private:
//   bool palindrome(string& s) {
//     int l = 0, r = s.size() - 1;
//     while (l < r && s[l] == s[r]) {
//       l++;
//       r--;
//     }
//     return l >= r;
//   }
//   void dfs(set<string>& sst, string& s, int i, string cur) {
//     // base
//     if (i == s.size()) {
//       if (palindrome(cur))
//         sst.insert(cur);
//       return;
//     }
//     // recursion
//     dfs(sst, s, i+1, cur);
//     dfs(sst, s, i+1, cur+s[i]);
//   }
//  public:
//   int countPalindromicSubsequences(string s) {
//     set<string> sst;
//     dfs(sst, s, 0, "");
//     return sst.size() - 1;
//   }
// };

//
//    i l
// s: a b c a
//        r j

// // DFS
// // O(3^N) O(N)
// class Solution {
//  private:
//   int dfs(string& s, int i, int j) {
//     // base
//     if (i > j)
//       return 0;
//     if (i == j)
//       return 1;
//     int ans = 0;
//     if (s[i] == s[j]) {
//       ans = 2 * dfs(s, i+1, j-1);
//       int left = i + 1, right = j - 1;
//       while (left <= right && s[left] != s[i])
//         left++;
//       while (left <= right && s[right] != s[i])
//         right--;
//       if (left < right) {
//         ans -= dfs(s, left+1, right-1);
//       } else if (left == right) {
//         ans += 1;
//       } else {
//         ans += 2;
//       }
//     } else {
//       ans = dfs(s, i+1, j) + dfs(s, i, j-1) + dfs(s, i+1, j-1);
//     }
//     return ans;
//   }
//  public:
//   int countPalindromicSubsequences(string s) {
//     return dfs(s, 0, s.size()-1); 
//   }
// };

// // dynamic programming recursive way
// class Solution {
//  public :
//   int countPalindromicSubsequences(string s) {
//   }
// };

// 164ms 69.08% 36.5MB 45.67%
// dynamic programming iterative way
// O(N^2) O(N^2)
#define MOD 1000000007
class Solution {
 public:
  int countPalindromicSubsequences(string s) {
    int n = s.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      C[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
      for (int i = 0; i < n-len+1; i++) {
        int j = i + len - 1;
        if (s[i] == s[j]) {
          int left = i + 1, right = j - 1;
          C[i][j] = 2 * C[i+1][j-1];
          while (left <= right && s[left] != s[i])
            left++;
          while (left <= right && s[right] != s[i])
            right--;
          if (left < right) {
            // no need to add two ends to the palindomes between inner 2a
            C[i][j] -= C[left+1][right-1];
          } else if (left == right) {
            // a...a...a, add aa
            C[i][j] += 1; 
          } else {
            // a...a, add a, aa
            C[i][j] += 2; 
          }
        } else {
          C[i][j] = C[i+1][j] + C[i][j-1] - C[i+1][j-1];
        }
        if (C[i][j] < 0) {
          C[i][j] = C[i][j] + MOD;
        } else {
          C[i][j] = C[i][j] % MOD;
        }
      }
    }
    return C[0][n-1];
  }
};

//    i
// s: a b c a
//          j
