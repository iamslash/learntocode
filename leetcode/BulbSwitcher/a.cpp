// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>

// find perfect squares
class Solution {
 public:
  int bulbSwitch(int n) {
    if (n == 0)
        return 0;
    int rslt = 0;
    for (int i = 1; i*i <= n; ++i)
      rslt++;
    return rslt;
  }
};


int main() {

  Solution sln;
  printf("%d\n", sln.bulbSwitch(3));
  
  return 0;
}
