/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <functional>

// 4ms 99.08%
class Solution {
 public:
  int singleNonDuplicate(std::vector<int>& V) {
    return std::accumulate(V.begin(), V.end(), 0, std::bit_xor<int>());
  }
};

int main() {

  std::vector<int> V0 = {1,1,2,3,3,4,4,8,8};
  std::vector<int> V1 = {3,3,7,7,10,11,11};
  Solution sln;
  printf("%d\n", sln.singleNonDuplicate(V0));
  printf("%d\n", sln.singleNonDuplicate(V1));
  
  return 0;
}
