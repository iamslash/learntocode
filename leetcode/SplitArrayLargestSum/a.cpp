/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <numeric>

// 4ms 100.00% 8.7MB 53.75%
// O(NlgN) O(1)
class Solution {
 private:
  int64_t mod = std::numeric_limits<int64_t>::max();
  // is paritionable with m groups, max number
  // maxgrp: max group
  // maxsum: max sum
  bool isPartAble(std::vector<int>& V, int maxgrp, int64_t maxsum) {
    int64_t sum = 0;
    int grp = 1;
    for (int num : V) {
      sum = (sum + num) % mod;
      if (sum > maxsum) {
        sum = num;
        grp++;
        if (grp > maxgrp)
          return false;
      }
    }
    return true;
  }
 public:
  int splitArray(std::vector<int>& V, int m) {
    // lsm : low sum
    // hsm : high sum
    int64_t lsm = *std::max_element(V.begin(), V.end());
    int64_t hsm = std::accumulate(V.begin(), V.end(), 0L);
    int64_t msm = 0;
    while (lsm < hsm) {
      msm = ((hsm + lsm) % mod) / 2;
      if (isPartAble(V, m, msm))
        hsm = msm;
      else
        lsm = msm + 1;
    }
    return hsm;    
  }
};

int main() {
  // std::vector<int> V = {7, 2, 5, 10, 8};
  std::vector<int> V = {1, 2147483646};
  int m = 1;

  Solution sln;
  printf("%d\n", sln.splitArray(V, m)); // 2147483647
  
  return 0;
}
