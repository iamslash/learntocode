/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <numeric>

// 220ms 30.26% 9.7MB 94.74%
// partial sum
// O(N^2)
class Solution {
 public:
  bool splitArray(std::vector<int>& V) {
    int n = V.size();
    if (n < 7)
      return false;
    std::vector<int> ps(n, 0);
    std::partial_sum(V.begin(), V.end(), ps.begin());

    // find a middle cut
    // asum + bsum
    for (int j = 3; j < n - 3; ++j) {
      std::unordered_set<int> hsum;  // half of sum
      for (int i = 1; i < j - 1; ++i) {
        int asum = ps[i-1];
        int bsum = ps[j-1] - ps[i];
        if (asum == bsum)
          hsum.insert(asum);
      }
      for (int k = j + 1; k < n - 1; ++k) {
        int csum = ps[k-1] - ps[j];
        int dsum = ps[n-1] - ps[k];
        if (csum == dsum && hsum.count(csum))
          return true;
      }
    }

    return false;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  std::vector<int> V = {1,2,1,2,1,2,1};
  Solution sln;
  printb(sln.splitArray(V));
  
  return 0;
}
