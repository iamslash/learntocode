/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

//  V: 1 7 4 9 2 5
// up: 1 2 2 4 4 6
// dn: 1 1 3 3 5 5
//
// 0ms 100%
class Solution {
 public:
  int wiggleMaxLength(std::vector<int>& V) {
    if (V.empty())
      return 0;
    int n = V.size();
    std::vector<int> up(n);  // wiggle max length when V[i] is up value
    std::vector<int> dn(n);  // wiggle max length when V[i] is down value

    up[0] = 1;
    dn[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (V[i] > V[i-1]) {
        up[i] = dn[i-1] + 1;
        dn[i] = dn[i-1];
      } else if (V[i] < V[i-1]) {
        dn[i] = up[i-1] + 1;
        up[i] = up[i-1];
      } else {
        dn[i] = dn[i-1];
        up[i] = up[i-1];
      }
    }
    
    return std::max(dn[n-1], up[n-1]);
  }
};

int main() {
  // std::vector<int> V = {1,7,4,9,2,5};
  std::vector<int> V = {1,17,5,10,13,15,10,5,16,8};
  
  Solution sln;
  printf("%d\n", sln.wiggleMaxLength(V));
  
  return 0;
}
