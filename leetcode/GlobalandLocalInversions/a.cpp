/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//     i
// 1 2 4 3 0
//

// 64ms 73.30% 12.7MB 43.24%
// O(N) O(1)
class Solution {
 public:
  bool isIdealPermutation(std::vector<int>& V) {
    int n = V.size();
    for (int i = 0; i < n; ++i)
      if (std::abs(V[i] - i) > 1)
        return false;
    return true;
  }
};

int main() {
  // std::vector<int> V = {1, 0, 2};
  std::vector<int> V = {1, 2, 0};
  Solution sln;
  printf("%s\n", sln.isIdealPermutation(V) ? "true" : "false");
  
  return 0;
}
