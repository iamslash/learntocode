/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 16ms 99.21% 13.2MB 46.58%
// math
// O(N) O(1)
class Solution {
 public:
  string largestMultipleOfThree(vector<int>& D) {
    vector<int> cand1 = {1, 4, 7, 2, 5, 8};
    vector<int> cand2 = {2, 5, 8, 1, 4, 7};
    int sum = 0, digitCnts[10] = {};
    for (int d : D) {
      ++digitCnts[d];
      sum += d;
    }
    while (sum % 3 != 0) {
      auto cand = cand1;
      if (sum % 3 == 2)
        cand = cand2;
      for (int i : cand) {
        if (digitCnts[i] > 0) {
          --digitCnts[i];
          sum -= i;
          break;
        }
      }
    }
    string ans;
    for (int i = 9; i >= 0; --i) {
      ans += string(digitCnts[i], '0' + i);      
    }
    if (ans.size() && ans[0] == '0')
      return "0";
    return ans;
  }
};
