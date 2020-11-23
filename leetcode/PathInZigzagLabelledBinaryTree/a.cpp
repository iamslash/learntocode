/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//            1
//       /        \
//      3          2
//    /   \      /   \
//   4     5     6    7
//  / \   / \   / \  / \
// 15 14 13 12 11 10 9  8  

// 14 7 3 1 0

// 0ms 100.00% 8.2MB 100.00%
// brute force
// O(lgN) O(N)
class Solution {
 public:
  std::vector<int> pathInZigZagTree(int lbl) {
    int lvl = 0;
    // 0 1 2 3 4
    // 1 2 4 8 16
    while (1 << lvl <= lbl)
      ++lvl;
    std::vector<int> ans(lvl);
    while (lbl >= 1) {
      ans[lvl-1] = lbl;
      // 2^3 + (2^4 - 1) - 14
      lbl = (1 << (lvl - 1)) + ((1 << lvl) - 1) - lbl;
      lbl /= 2;
      lvl--;
    }
    return ans;
  }
};

int main() {

  Solution sln;
  auto r = sln.pathInZigZagTree(14);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  return 0;
}
