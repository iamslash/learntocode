/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// -4 -2 2 4

// 108ms 58.90% 14.5% 90.0%
// hash table
// O(N) O(N)
class Solution {
 public:
  bool canReorderDoubled(std::vector<int>& A) {
    std::map<int, int> smp;
    for (int a : A)
      smp[a]++;
    for (auto& pr : smp) {
      int a = pr.first;
      if (!smp[a])
        continue;
      if (a < 0) {
        if (a & 1 || smp[a/2] < smp[a])
          return false;
        smp[a/2] -= smp[a];
      } else {
        if (smp[2*a] < smp[a])
          return false;
        smp[2*a] -= smp[a];
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
