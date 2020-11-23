/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 12ms 97.08% 9.2MB 86.38%
// iterative dynamic programming
// O(N) O(N)
#define MIN_VAL -10000
class Solution {
 public:
  string largestNumber(vector<int>& cost, int tgt) {
    vector<int> C(tgt+1, MIN_VAL);
    C[0] = 0;
    for (int t = 1; t <= tgt; ++t) {
      for (int i = 0; i < 9; ++i) {
        int cnt = MIN_VAL;
        if (t >= cost[i])
          cnt = 1 + C[t - cost[i]];
        C[t] = max(C[t], cnt);
      }
    }
    if (C[tgt] < 0)
      return "0";
    string ans = "";
    for (int i = 8; i >= 0; --i) {
      while (tgt >= cost[i] && C[tgt] == C[tgt-cost[i]] + 1) {
        ans.push_back('1' + i);
        tgt -= cost[i];
      }
    }
    return ans;
  }
};
