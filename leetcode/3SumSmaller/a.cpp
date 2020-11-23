/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//     i j   k
// V: -2 0 1 3
// t:  2

// 8ms 100.00% 8.6MB 71.43%
// O(N^2) O(1)
class Solution {
 public:
  int threeSumSmaller(std::vector<int>& V, int tgt) {
    int n = V.size();
    if (n < 3)
      return 0;
    std::sort(V.begin(), V.end());
    int r = 0;
    for (int i = 0; i < n-2; ++i) {
      int j = i+1, k = n-1;
      while (j < k) {
        int sum = V[i]+V[j]+V[k];
        if (sum < tgt) {
          r += k - j;
          ++j;
        } else {
          --k;
        }
      }
    }
    return r;
  }
};

int main() {
  std::vector<int> V = {-2, 0, 1, 3};
  int tgt = 2;
  Solution sln;
  printf("%d\n", sln.threeSumSmaller(V, tgt));
  
  return 0;
}
