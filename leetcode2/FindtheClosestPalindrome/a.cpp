/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

// 4ms 59.75% 6.6MB 12.26%
// set
// O(N) O(N)
class Solution {
 public:
  string nearestPalindromic(string s) {
    int n = s.size();
    set<int64_t> candSet;
    // 10...01
    candSet.insert(int64_t(pow(10, n)) + 1);
    // 9..9 or 0
    candSet.insert(int64_t(pow(10, n-1)) - 1);
    int64_t prefix = stol(s.substr(0, (n + 1) / 2));
    for (int64_t i = -1; i <= 1; ++i) {
      string p = to_string(prefix + i);
      string q = p + string(p.rbegin() + (n & 1), p.rend());
      candSet.insert(stol(q));
    }
    int64_t num = stol(s);
    int64_t minDiff = LONG_MAX, diff, minVal;
    candSet.erase(num);
    for (int64_t val : candSet) {
      diff = abs(val - num);
      if (diff < minDiff) {
        minDiff = diff;
        minVal = val;
      } else if (diff == minDiff) {
        minVal = min(minVal, val);
      }
    }
    return to_string(minVal);
  }
};
