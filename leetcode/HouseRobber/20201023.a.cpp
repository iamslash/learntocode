/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//             i
// num : 1 2 3 1
//
// tmp : 1 2 4 4 
// pre : 0 1 2 4
// cur : 1 2 4 4
class Solution {
 public:
  int rob(const std::vector<int>& V) {
    int pre = 0, cur = 0, tmp = 0;
    for (int i = 0; i < V.size(); ++i) {
      // max of
      //   not previous robbing, current robbing -> pre + V[i]
      //   previous robbing, not current robbing -> cur
      tmp = std::max(pre + V[i], cur);
      pre = cur;
      cur = tmp;
    }
    return cur;
  }
};

int main() {

  std::vector<int> V1 = {1, 2, 3, 1};
  std::vector<int> V2 = {2, 7, 9, 3, 1};
  std::vector<int> V3 = {1, 2, 100, 1, 2, 1};

  Solution sln;
  printf("%d\n", sln.rob(V1));
  printf("%d\n", sln.rob(V2));
  printf("%d\n", sln.rob(V3));
  
  return 0;
}
