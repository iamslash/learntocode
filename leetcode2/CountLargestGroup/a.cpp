/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>

using namespace std;

// 8ms 60.81% 6.4MB 25.45%
class Solution {
 private:
  int sumDigit(int n) {
    // base
    if (n == 0)
      return 0;
    // recursion
    return n % 10 + sumDigit(n/10);
  }
 public:
  int countLargestGroup(int n) {
    unordered_map<int, int> cnts;
    int maxSumDigit = 0;
    for (int i = 1; i <= n; ++i) {
      maxSumDigit = max(maxSumDigit, ++cnts[sumDigit(i)]);
    }
    int ans = 0;
    for (auto pr : cnts) {
      if (pr.second == maxSumDigit)
        ans++;
    }
    return ans;
  }
};
