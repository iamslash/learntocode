/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

//                   i
//   s1: a c b a c b a c b a c b
//   s2: a b a b
//         j
// cnt1: 0
// cnt2: 1


// // Time Limit Exceeded
// // brute force
// // O(N) O(1)
// class Solution {
//  public:
//   int getMaxRepetitions(string s1, int n1, string s2, int n2) {
//     int cnt1 = 0, cnt2 = 0, i = 0, j = 0;
//     while (cnt1 < n1) {
//       if (s1[i] == s2[j]) {
//         j++;
//         if (j == s2.size()) {
//           j = 0;
//           cnt2++;
//         }
//       }
//       i++;
//       if (i == s1.size()) {
//         i = 0;
//         cnt1++;
//       }
//     }
//     return cnt2 / n2;
//   }
// };

//             c
//   s1: a c b
//           i
//   s2: a b   
//       s
//  len: 2
//    C: 2 0 
//  idx: 8
//  ans: 2

// It's too difficult.
// 128ms 6.67% 6.3MB 74.07%
// dynamic programming
// O(N) O(N)
class Solution {
 public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int len = s2.size();
    vector<int> C(len);
    for (int i = 0; i < len; ++i) {
      int start = i;
      for (char c : s1) {
        if (c == s2[start % len])
          start++;
        C[i] = start - i;
      }
    }
    int idx = 0;
    for (int i = 0; i < n1; ++i) {
      idx += C[idx % len];
    }
    return idx / len / n2;
  }
};

