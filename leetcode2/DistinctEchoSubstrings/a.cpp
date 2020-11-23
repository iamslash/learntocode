/* Copyright (C) 2020 by iamslash */

// https://github.com/iamslash/learntocode/blob/master/fundamentals/hash/rollinghash/README.md

#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// // Time Limit Exceeded
// // 0   45
// // abcabcabc
// // hash table
// // O(N) O(N)
// class Solution {
//  public:
//   int distinctEchoSubstrings(string s) {
//     unordered_set<string> ans;
//     int n = s.length();
//     for (int i = 0; i < n; i++) {
//       for (int j = 2; i + j <= n; j += 2) {
//         int k = j / 2;
//         string a = s.substr(i, k);
//         string b = s.substr(i+k, k);
//         if (a == b)
//           ans.insert(a);
//         // printf("i: %d, j: %d, k: %d, a: %s, b: %s\n", i, j, k, a.c_str(), b.c_str());
//       }
//     }
//     return ans.size();
//   }
// };

//      l
//   s: a b c a b c a
//          r
// len: 3
// cnt: 3
// ans:

//        i 
//   s: a b a b
//            j  
// len: 2
// cnt: 2

// // Memory Limit Exceeded
// // rolling counter
// // O(N^2) O(N)
// class Solution {
//  public:
//   int distinctEchoSubstrings(string s) {
//     unordered_set<string> ans;
//     int n = s.length();
//     for (int len = 1, cnt = 0; len <= n/2; len++) {
//       for (int i = 0, j = len; i + len < n; i++, j++) {
//         cnt = s[i] == s[j] ? cnt + 1 : 0;
//         if (cnt == len) {
//           ans.insert(s.substr(i,len));
//           cnt--;
//         }
//       }
//     }
//     return ans.size();
//   }
// };

// 208ms 82.20% 7.5MB 50.00%
// rolling hash
// O(N^2) O(N)
class Solution {
 private:
  int R = 256;
  int64_t Q = 1000000007L;
  vector<int64_t> pshash;
  vector<int64_t> pspow;
  void build(int n, string& s) {
    pshash.resize(n+1);
    pspow.resize(n+1);
    pspow[0] = 1;
    for (int i = 1; i <= n; ++i) {
      pshash[i] = (pshash[i-1] * R + s[i-1]) % Q;
      pspow[i] = (pspow[i-1] * R) % Q;
    }
  }
  int64_t getHash(int l, int r) {
    return (pshash[r] + Q - pshash[l] * pspow[r-l] % Q) % Q;
  }
 public:
  int distinctEchoSubstrings(string s) {
    unordered_set<int64_t> ans;
    int n = s.length();
    build(n, s);
    for (int len = 1; len <= n/2; len++) {
      for (int i = 0, j = len, cnt = 0; i + len < n; i++, j++) {
        cnt = s[i] == s[j] ? cnt + 1 : 0;
        if (cnt == len) {
          ans.insert(getHash(i-len+1, i+1));
          cnt--;
        }
      }
    }
    return ans.size();
  }
};

