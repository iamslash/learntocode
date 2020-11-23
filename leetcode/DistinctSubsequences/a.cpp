/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

//   0 r a b b i t
// 0 1 0 0 0 0 0 0
// r 1 1 0 0 0 0 0            
// a 1 1 1 0 0 0 0
// b 1 1 1 1 0 0 0 
// b 1 1 1 2 1 0 0
// b 1 1 1 3 3 0 0
// i 1 1 1 3 3 3 0
// t 1 1 1 3 3 3 3

// 8ms 98.33% 8.6MB 100.00%
// dynamic programming
// O(ST) O(T)
class Solution {
 public:
  int numDistinct(std::string s, std::string t) {
    int ns = s.size();
    int nt = t.size();
    if (ns == 0)
      return 0;
    if (nt == 0)
      return 1;
    std::vector<int64_t> C(nt+1, 0);
    C[0] = 1;
    for (int y = 1; y <= ns; ++y) {
      int64_t prev = 1;
      for (int x = 1; x <= nt; ++x) {
        int temp = C[x];
        if (y >= x && s[y-1] == t[x-1])
          C[x] += prev;
        prev = temp;
      }
      printf("1 ");
      for (int x = 1; x <= nt; ++x) {
        printf("%lld ", C[x]);
      }
      printf("\n");
    }
    return C[nt];
  }
};

int main() {

  Solution sln;
  // printf("%d\n", sln.numDistinct("rabbbit", "rabbit"));
  printf("%d\n", sln.numDistinct("rabb", "rabb"));
  // printf("%d\n", sln.numDistinct("adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc",
  //                                "bcddceeeebecbc"));
  

  
  return 0;
}
