/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//     i
// 0 1 3 5 6
//
class Solution {
 public:
  int hIndex(const std::vector<int>& V) {
    std::sort(V.begin(), V.end());
    int n = V.size();
    for (int i = 0; i < n; ++i) {
      int h = n-i;
      if (V[i] >= h)
        return h;
    }
    return 0;
  }
};

int main() {

  std::vector<int> V0 = {3, 0, 6, 1, 5};
  std::vector<int> V1 = {1, 1, 1, 1, 1};
  std::vector<int> V2 = {1, 1};

  Solution sln;
  printf("%d\n", sln.hIndex(V0));
  printf("%d\n", sln.hIndex(V1));
  printf("%d\n", sln.hIndex(V2));
  
  return 0;
}
