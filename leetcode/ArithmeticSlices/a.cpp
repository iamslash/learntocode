/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

//   i
//     j
// 1 2 3 4
// 0ms 100%
class Solution {
 public:
  int numberOfArithmeticSlices(std::vector<int>& V) {
    if (V.size() < 3)
      return 0;
    int rslt = 0;
    
    for (int i = 1; i < V.size()-1; ++i) {
      int d = V[i] - V[i-1];
      for (int j = i; j < V.size() && (V[j]-V[j-1]==d); ++j) {
        if (j-i >= 1)
          rslt++;
      }
    }

    return rslt;
  }
};

int main() {
  std::vector<int> V = {1, 2, 3, 4};
  Solution sln;
  printf("%d\n", sln.numberOfArithmeticSlices(V));

  return 0;
}
