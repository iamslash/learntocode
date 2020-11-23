/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

// 100ms 93.67% 12.2MB 81.16%
// binary search
// O(NlgN) O(1)
class Solution {
 private:
  bool isLarger(std::vector<int>& V, double midavg, int k) {
    // cursum: sum of from V[0] to V[i]
    // prvsum: sum of from V[0] to V[i-k]
    // minsum: min sum of from V[0] to V[j] (0 <= j <= i-k)    
    double cursum = 0, prvsum = 0, minsum = 0;
    int n = V.size();
    for (int i = 0; i < n; ++i) {
      cursum += V[i] - midavg;
      if (i >= k) {
        prvsum += V[i-k] - midavg;
        minsum = std::min(minsum, prvsum);
      }
      if (i >= k-1 && cursum > minsum)
        return false;
    }
    return true;
  }
 public:
  double findMaxAverage(std::vector<int>& V, int k) {
    double lft = INT_MAX;
    double rgt = INT_MIN;
    double mid;
    for (int n : V) {
      rgt = std::max(rgt, (double)n);
      lft = std::min(lft, (double)n);
    }
    while (lft + 0.00001 < rgt) {
      mid = (lft + rgt) / 2;
      if (isLarger(V, mid, k))
        rgt = mid;
      else
        lft = mid;
    }
    return lft;
  }
};

int main() {
  std::vector<int> V = {1, 12, -5, -6, 50, 3};
  int k = 4;
  Solution sln;
  printf("%.2lf\n", sln.findMaxAverage(V, k));
  
  return 0;
}
