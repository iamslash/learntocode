/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <queue>

//               r
//               l
// 0 1 0 2 1 0 1 3 2 1 2 1
//
// maxl: 2
// maxr: 2
// rslt: 6
//
// 12ms 40.13%
class Solution {
 public:
  int trap(std::vector<int>& H) {
    int l = 0, r = H.size()-1;
    int rslt = 0;
    int maxl = 0, maxr = 0;

    while (l <= r) {
      if (H[l] <= H[r]) {
        if (H[l] >= maxl)
          maxl = H[l];
        else
          rslt += maxl - H[l];
        l++;
      } else {
        if (H[r] >= maxr)
          maxr = H[r];
        else
          rslt += maxr - H[r];
        r--;
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<int> H = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution sln;
  printf("%d\n", sln.trap(H));
  
  return 0;
}
