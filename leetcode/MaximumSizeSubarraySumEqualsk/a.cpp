/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include <unordered_map>

//        i             
// 1, -1, 5, -2, 3
//   k: 3
// sum: 5
// psm: {-3:0, -2:0, 1:1}
// len: 1
// max;

// 44ms 45.09% 13.8MB 27.17%
// partial sum map
// O(N) O(N)
class Solution {
 public:
  int maxSubArrayLen(std::vector<int>& V, int k) {
    // partial sum : index
    std::unordered_map<int, int> ump;
    ump[0] = -1;
    int sum = 0;
    int rst = 0;
    for (int i = 0; i < V.size(); ++i) {
      sum += V[i];
      if (ump.count(sum) == 0)
        ump[sum] = i;
      int tgt = sum - k;
      if (ump.count(tgt))
        rst = std::max(rst, (i-ump[tgt]));
    }
    return rst;
  }
};

int main() {

  std::vector<int> V = {1, -1, 5, -2, 3};
  int k = 3;
  Solution sln;
  printf("%d\n", sln.maxSubArrayLen(V, k));
  
  return 0;
}
