/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//       i
// num : 1 2 3 1
//
// tmp : 1 2 4 4
// pre : 0 1 2 4
// cur : 1 2 4 4

// 4ms 21.30 % 
class Solution {
 public:
  int _rob(const std::vector<int>& V, int l, int r) {
    int pre = 0;
    int cur = 0;
    int tmp = 0;
    for (int i = l; i <= r; ++i) {
      tmp = std::max(pre + V[i], cur);
      pre = cur;
      cur = tmp;
    }
    return cur;
  }
  int rob(const std::vector<int>& V) {
    if (V.empty())
      return 0;
    if (V.size() == 1)
      return V[0];
    return std::max(_rob(V, 0, V.size()-2),
                    _rob(V, 1, V.size()-1));
  }
};

int main() {
  std::vector<int> V1 = {2, 3, 2};
  std::vector<int> V2 = {1, 2, 3, 1};
  std::vector<int> V3 = {1, 100};
  
  Solution sln;
  printf("%d\n", sln.rob(V1)); 
  printf("%d\n", sln.rob(V2)); 
  printf("%d\n", sln.rob(V3)); 
  return 0;
}
