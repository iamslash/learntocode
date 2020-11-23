/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//     i
// 1 0 1 1 0 1 1 1
//                 j
// m:

// 40ms 80.74% 11.9MB 73.17%
// prev 1s + 0 + current 1s
// O(N) O(1)
class Solution {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& V) {
    int prv = 0;
    int cur = 0;
    int rst = 0;
    for (int i : V) {
      if (i == 1) {
        cur++;
      } else {
        prv = cur + 1;
        cur = 0;
      }
      rst = std::max(rst, cur + prv);
    }
    return rst;
  }
};

int main() {
  // std::vector<int> V = {1, 0, 1, 1, 0};
  std::vector<int> V = {1, 0, 1, 1, 0, 1, 1, 1};
  Solution sln;
  printf("%d\n", sln.findMaxConsecutiveOnes(V));
  
  return 0;
}
