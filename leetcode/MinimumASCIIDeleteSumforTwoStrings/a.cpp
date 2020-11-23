/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

//   0 s e a
// 0 0 . . .
// e . . . 
// a .   
// t .

// 20ms 100.00% 9.4MB 93.33%
// dynamic programming
// O(AB) O(B)
class Solution {
 public:
  int minimumDeleteSum(std::string a, std::string b) {
    int h = a.size();
    int w = b.size();
    std::vector<int> C(w+1, 0);
    for (int x = 1; x <= w; ++x)
      C[x] = C[x-1]+b[x-1];
    for (int y = 1; y <= h; ++y) {
      int prev = C[0];
      C[0] += a[y-1];
      for (int x = 1; x <= w; ++x) {
        int tmp = C[x];
        C[x] = a[y-1] == b[x-1] ?
            prev :
            std::min(C[x]+a[y-1], C[x-1]+b[x-1]);
        prev = tmp;
      }
    }
    return C[w];
  }
};

int main() {
  Solution sln;
  // printf("%d\n", sln.minimumDeleteSum(a, b));
  printf("%d\n", sln.minimumDeleteSum("ccaccjp", "fwosarcwge")); // 1399
  return 0;
}
