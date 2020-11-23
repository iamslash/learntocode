/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <stack>

using namespace std;

//                     i
//    s: a a b a b b a b
// stck: a b
//  ans: 2

//                     i
//    s: a a b a b b a b
// cntB: 2
//  ans: 2

// 216ms 19.18% 23.5MB 51.55%
// stack
// O(N) O(N)
class Solution {
 public:
  int minimumDeletions(string s) {
    stack<char> stck;
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (stck.size() && stck.top() > c) {
        ans++;
        stck.pop();
      } else {
        stck.push(c);
      }
    }
    return ans;
  }
};

// 80ms 99.63% 22.4MB 81.37%
// greedy algorithm
// O(N) O(1)
class Solution {
 public:
  int minimumDeletions(string s) {
    int n = s.size(), ans = 0, cntB = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'b') {
        cntB++;
      } else {
        if (cntB > 0) {
          ans++;
          cntB--;
        }
      }
    }
    return ans;
  }
};

//                     i
//    s: a a b a b b a b
// aCnt: 0
// bCnt: 4
//  ans: 2

// 168ms 47.80% 22.3MB 94.45%
// greedy algorithm, local max global max
// O(N) O(1)
class Solution {
 public:
  int minimumDeletions(string s) {
    int aCnt = count(s.begin(), s.end(), 'a');
    int n = s.size(), bCnt = 0, ans = max(aCnt, bCnt);
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'a') {
        aCnt--;
      } else {
        bCnt++;
      }
      ans = min(ans, aCnt+bCnt);
    }
    return ans;
  }
};
