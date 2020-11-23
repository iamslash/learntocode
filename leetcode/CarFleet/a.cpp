/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// tgt: 12
//   P: 10 8 0 5 3
//   S:  2 4 1 1 3
//   m: 10 8 0 5 3
//       1 112 7 3

// 56ms 52.98% 14.5MB 32.59%
// O(PlgP) O(P)
class Solution {
 public:
  int carFleet(int tgt, std::vector<int>& P,
               std::vector<int>& S) {
    int n = P.size();
    // { position : time to target, ... }
    std::map<int, double> smp;
    for (int i = 0; i < n; ++i)
      smp[-P[i]] = (double)(tgt - P[i])/S[i];
    int r = 0;
    double cur = 0.0;
    for (auto& pr : smp) {
      if (pr.second > cur) {
        cur = pr.second;
        r++;
      }
    }
    return r;
  }
};

int main() {
  return 0;
}
