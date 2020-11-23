/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// 92ms 83.46% 19.1MB 42.06%
// O(NlgN) O(N)
class Solution {
 public:
  int oddEvenJumps(std::vector<int>& A) {
    int n = A.size(), ans = 1;
    // higher values, lower values
    std::vector<int> hier(n), loer(n);
    hier[n-1] = loer[n-1] = 1;
    // {A[i] : i}
    std::map<int, int> smp;
    smp[A[n-1]] = n-1;
    for (int i = n-2; i >= 0; --i) {
      auto ithi = smp.lower_bound(A[i]);
      auto itlo = smp.upper_bound(A[i]);
      if (ithi != smp.end())
        hier[i] = loer[ithi->second];
      if (itlo != smp.begin())
        loer[i] = hier[(--itlo)->second];
      if (hier[i])
        ans++;
      smp[A[i]] = i;
    }
    return ans;
  }
};

int main() {
  return 0;
}
