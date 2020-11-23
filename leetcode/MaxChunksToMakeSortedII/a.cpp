/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//   i
// 2 1 3 4 4
// 1 2 3 4 4


// i
// 5 4 3 2 1
// 1 2 3 4 5
// 16ms 57.14% 6.4MB 3.09%
// O(NlgN) O(N)
class Solution {
 public:
  int maxChunksToSorted(std::vector<int>& V) {
    int64_t sum1 = 0, sum2 = 0, rslt = 0;
    std::vector<int> T = V;
    std::sort(T.begin(), T.end());
    for (int i = 0; i < V.size(); ++i) {
      sum1 += T[i];
      sum2 += V[i];
      if (sum1 == sum2) {
        rslt++;
        sum1 = sum2 = 0;
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<int> V = {2,1,3,4,4};
  Solution sln;
  printf("%d\n", sln.maxChunksToSorted(V));
  return 0;
}
