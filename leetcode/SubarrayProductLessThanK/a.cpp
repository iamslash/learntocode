/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//    i
//        j
// 10 5 2 6

// 132ms 13.10% 18.7MB 57.14%
// O(N^2) O(1)
class Solution {
 public:
  int numSubarrayProductLessThanK(std::vector<int>& V, int k) {
    if (k == 0)
      return 0;
    int cnt = 0;
    int prd = 1;
    for (int i = 0, j = 0; j < V.size(); ++j) {
      prd *= V[j];
      while (i <= j && prd >= k) {
        prd /= V[i++];
      }
      cnt += j - i + 1;
    }
    return cnt;
  }
};
int main() {
  std::vector<int> V = {10, 5, 2, 6};
  int k = 100;

  Solution sln;
  printf("%d\n", sln.numSubarrayProductLessThanK(V, k));
  
  return 0;
}
