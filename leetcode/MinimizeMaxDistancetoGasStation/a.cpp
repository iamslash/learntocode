/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 36ms 95.43% 9.5MB 58.98%
// binary search
// O(NlgN) O(1)
class Solution {
 private:
  bool possible(std::vector<int>& S, int K, double D) {
    int n = S.size();
    int need = 0;
    for (int i = 0; i < n-1; ++i)
      need += (int)((S[i+1] - S[i])/D);
    return need <= K;
  }
 public:
  double minmaxGasDist(std::vector<int>& S, int K) {
    double lo = 0, hi = 1e8, mi;
    while (lo + 1e-6 < hi) {
      mi = (lo + hi) / 2;
      if (possible(S, K, mi))
        hi = mi;
      else
        lo = mi;
    }
    return lo;
  }
};

int main() {

  std::vector<int> S = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int K = 9;

  Solution sln;
  printf("%lf\n", sln.minmaxGasDist(S, K));
  
  return 0;
}
