/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//  1  2  3
// 01 10 11

//  1  2   4
// 01 10 100

// 12ms 100.00% 9.9MB 0.00%
// O(N) O(1)
class Solution {
 public:
  bool xorGame(std::vector<int>& V) {
    int rslt = 0;
    for (int a : V)
      rslt ^= a;
    // 0. xor of V is 0 means bob already losed.
    // 1. size of V is even alice can choose anything to win.
    return rslt == 0 || V.size() % 2 == 0;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  std::vector<int> V = {1, 1, 2};
  
  Solution sln;
  printb(sln.xorGame(V));
  
  return 0;
}
