/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

// 368ms 83.57% 65.3MB 7.19%
// sort
// O(NlgN) O(1)
#define MOD 1000000007
class Solution {
 public:
  int maxProfit(vector<int>& I, int orders) {
    int64_t ans = 0, colors = 1;
    sort(I.begin(), I.end());
    for (int i = I.size() - 1; i >= 0 && orders > 0;
         --i, ++colors) {
      int64_t prv = i == 0 ? 0 : I[i-1];
      int64_t cur = I[i];
      int64_t rnd = min(orders / colors, cur - prv);
      orders -= rnd * colors;
      ans = (ans + (cur * (cur + 1) - (cur - rnd) * (cur - rnd + 1))
             / 2 * colors) % MOD;
      if (cur - prv > rnd) {
        ans = (ans + orders * (cur - rnd)) % MOD;
        break;
      }          
    }
    return ans;
  }
};
