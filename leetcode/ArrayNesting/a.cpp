/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 20ms 95.45%
// O(N) O(1)
class Solution {
 public:
  int arrayNesting(std::vector<int>& N) {
    int max_cnt = 0;
    for (int i = 0; i < N.size(); ++i) {
      if (N[i] < 0)
        continue;
      int loc_cnt = 0;
      int j = N[i];
      while (N[j] >= 0) {
        // printf("i: %d, j: %d\n", i, j);        
        int t = N[j];
        N[j] = -1;
        j = t;
        loc_cnt++;        
      }
      max_cnt = std::max(max_cnt, loc_cnt);
    }
    return max_cnt;
  }
};

int main() {

  std::vector<int> N = {5, 4, 0, 3, 1, 6, 2};

  Solution sln;
  printf("%d\n", sln.arrayNesting(N));
  
  return 0;
}
