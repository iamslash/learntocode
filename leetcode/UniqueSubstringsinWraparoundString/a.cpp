/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
//        c
//       abcd.z
//    C: 2331 1
//    p: zabdabcd
//              i
//  len: 4
// rslt: 7
//
// 8ms 75.00%
class Solution {
 public:
  int findSubstringInWraproundString(std::string p) {
    // C[i] : length of s ends with i+'a' char.
    std::vector<int> C(26, 0);
    int rslt = 0, len = 0;
    for (int i = 0; i < p.size(); ++i) {
      int cur = p[i] - 'a';
      if (i > 0 && ((p[i-1] - 'a') != ((cur + 25) % 26)))
        len = 0;
      if (++len > C[cur]) {
        rslt += len - C[cur];
        C[cur] = len;
      }
    }
    return rslt;
  }
};
 
int main() {

  Solution sln;
  printf("%d\n", sln.findSubstringInWraproundString("a"));
  printf("%d\n", sln.findSubstringInWraproundString("cac"));
  printf("%d\n", sln.findSubstringInWraproundString("zab"));
  
  return 0;
}
