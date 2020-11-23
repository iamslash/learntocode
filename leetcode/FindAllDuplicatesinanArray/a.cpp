// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <cmath>

class Solution {
 public:
  std::vector<int> findDuplicates(std::vector<int>& V) {
    std::vector<int> rslt;
    for (int i = 0; i < V.size(); ++i) {
      int idx = std::abs(V[i]) - 1;
      if (V[idx] < 0)
        rslt.push_back(std::abs(V[i]));
      else
        V[idx] = -V[idx];
    }
    return rslt;
  }
};

int main() {
  std::vector<int> V = {4, 3, 2, 7, 8, 2, 3, 1};

  Solution sln;
  auto rslt = sln.findDuplicates(V);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");

  return 0;
}
