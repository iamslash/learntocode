/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

class Solution {
 public:
  int findMin(std::vector<int>& V) {
    if (V.size() == 1)
      return V[0];
    int i = 1;
    for (i = 1; i < V.size(); i++) {
      if (V[i-1] > V[i])
        break;
    }
    return i == V.size() ? V[0] : V[i];
  }
};

int main() {
  // std::vector<int> V = {3, 4, 5, 1, 2};
  std::vector<int> V = {4, 5, 6, 7, 0, 1, 2};

  Solution s;
  printf("%d ", s.findMin(V));
  
  return 0;
}
