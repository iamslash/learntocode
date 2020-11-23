/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

// l
//       r
//       m
// i
// 10909091

// 4ms 100.00% 8.9MB 85.45%
// O(N) O(N)
class Solution {
 public:
  int maximumSwap(int n) {
    std::string s = std::to_string(n);
    int i, j;
    int maxi = -1, maxd = -1;
    int l = -1, r = -1;
    for (int i = s.size()-1; i >=0; --i) {
      if (s[i] > maxd) {
        maxd = s[i];
        maxi = i;
      } else if (s[i] < maxd) {
        l = i;
        r = maxi;
      }
    }
    if (l == -1)
      return n;
    std::swap(s[l], s[r]);    
    return std::stoi(s);
  }
};

//  i
//   j
//         k
//       m 
// 10909091
int main() {
  // int n = 2736;
  // int n = 9876;
  // int n = 1993;
  // int n = 1;
  // int n = 11;
  // int n = 1134886;
  int n = 10909091;
  
  Solution sln;
  printf("%d\n", sln.maximumSwap(n));
  
  return 0;
}
