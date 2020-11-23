/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// l
//         r
//     m
// 2 2 2 0 1
// 8ms 100.00% 9MB 6.25%
// O(lgN) O(1)
class Solution {
 public:
  int findMin(std::vector<int>& V) {
    int l = 0;
    int r = V.size()-1;
    int m;
    while (l < r) {
      m = (l+r)/2;
      if (V[m] > V[r])
        l = m + 1;
      else if (V[m] < V[r])
        r = m;
      else
        r--;      
    }
    return V[l];
  }
};

int main() {

  std::vector<int> V = {1, 3, 5};
  // std::vector<int> V = {2, 2, 2, 0, 1};
  
  Solution sln;
  printf("%d\n", sln.findMin(V));
  
  return 0;
}
