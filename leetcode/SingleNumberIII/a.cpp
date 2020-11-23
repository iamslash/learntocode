/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>


//     i
// v : 1 2 1 3 2 5
//
//

// 1100
// 0100
// 8ms 98.78%
class Solution {
 public:
  std::vector<int> singleNumber(std::vector<int>& V) {
    // 
    int diff = std::accumulate(V.begin(), V.end(), 0, std::bit_xor<int>());
    diff &= -diff;  // ex. 1100 &= 0100
    
    //
    std::vector<int> rslt = {0, 0};
    for (int v : V) {
      int i = (v & diff) == 0 ? 0 : 1;
      rslt[i] ^= v;
    }
    return rslt;
  }
};

int main() {
  std::vector<int> V0 = {1, 2, 1, 3, 2, 5};

  Solution sln;
  auto rslt = sln.singleNumber(V0);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");
  
  return 0;
}
