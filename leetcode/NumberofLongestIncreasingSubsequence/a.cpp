/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//               i
//             j
//    V: 1 3 5 4 7
// lens: 0 1 2 2 3 
// cnts: 1 1 1 1 2

//               i
//             j
//    V: 2 2 2 2 2
// lens: 0 0 0 0 0 
// cnts: 1 1 1 1 1

// 44ms 93.88% 10.5MB 28.57%
// O(N^2) O(N)
class Solution {
 public:
  int findNumberOfLIS(std::vector<int>& V) {
    int mod = 1e9+7;
    int n = V.size();
    if (n <= 1)
      return n;
    std::vector<int> lens(n, 0);
    std::vector<int> cnts(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (V[j] >= V[i])
          continue;
        if (lens[j] >= lens[i]) {
          lens[i] = lens[j] + 1;
          cnts[i] = cnts[j];
        } else if (lens[j]+1 == lens[i]) {
          cnts[i] = (cnts[i] + cnts[j]) % mod;
        }
      }
    }
    int maxlen = *std::max_element(lens.begin(), lens.end());
    int rslt = 0;
    for (int i = 0; i < n; ++i) {
      if (lens[i] == maxlen)
        rslt = (rslt + cnts[i]) % mod;
    }
    return rslt;
  }
};

int main() {
  // std::vector<int> V = {1, 3, 5, 4, 7};
  std::vector<int> V = {1,2,4,3,5,4,7,2};
  Solution sln;
  printf("%d\n", sln.findNumberOfLIS(V));  
  return 0;
}
