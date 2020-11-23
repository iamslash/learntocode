/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 5 3 4 5
class Solution {
 public:
  bool stoneGame(std::vector<int>& P) {
    std::vector<int> C = P;
    for (int i = 1; i < P.size(); ++i) {
      for (int j = 0; j < P.size() - i; ++j) {
        C[j] = std::max(P[j] - C[j+1], P[j+i] - C[j]);
      }
    }
    return C[0] > 0; // alex wins ?
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  std::vector<int> V = {5, 3, 4, 5};
  
  Solution sln;
  printb(sln.stoneGame(V));  
  return 0;
}
