/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// r: 2
// m: 2
//        i
// V: 1 0 2 3 4

// Q. what is the range of V.size()? [1..10]
// 4ms 100.00% 8.6MB 41.82%
// O(N) O(1)
class Solution {
 public:
  int maxChunksToSorted(std::vector<int>& V) {
    int n = V.size();
    int maxnum = -1;
    int r = 0;
    for (int i = 0; i < n; ++i) {
      maxnum = std::max(V[i], maxnum);
      if (i == maxnum)
        r++;
    }
    return r;
  }
};

int main() {
  // std::vector<int> V = {4, 3, 2, 1, 0};
  std::vector<int> V = {1, 0, 2, 3, 4};
  Solution sln;
  printf("%d\n", sln.maxChunksToSorted(V));
  return 0;
}
