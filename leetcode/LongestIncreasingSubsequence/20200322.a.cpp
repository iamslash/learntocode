/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 
// A: 1, 3, 6, 7, 9, 4, 10, 5, 6
//   

// 4ms 94.74% 8.7MB 40.32%
// O(N) O(N)
class Solution {
 public:
  int lengthOfLIS(std::vector<int>& V) {
    int n = V.size(), r = 0;
    for (int x : V) {
      int i = std::lower_bound(V.begin(), V.begin()+r, x) - V.begin();
      V[i] = x;
      if (i == r)
        ++r;   
    }
    return r;
  }
};

int main() {

  // std::vector<int> V = {10, 9, 2, 5, 3, 7, 101, 18};
  std::vector<int> V = {1, 3, 6, 7, 9, 4, 10, 5, 6};

  Solution sln;

  printf("%d\n", sln.lengthOfLIS(V));
  
  return 0;
}
