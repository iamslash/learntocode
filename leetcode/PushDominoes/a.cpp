/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

//         i 
//  .L.R...LR..L..
//          j


// 20ms 97.44%
// O(N) O(1)
class Solution {
 public:
  std::string pushDominoes(std::string D) {
    D = 'L' + D + 'R';
    int i = 0, j = 1, n = D.size();
    while (j < n) {
      while (j < n && D[j] == '.') {
        ++j;
      }
      if (D[i] == 'L' && D[j] == 'L') {
        for (int k = i + 1; k < j; ++k)
          D[k] = 'L';
      } else if (D[i] == 'R' && D[j] == 'R') {
        for (int k = i + 1; k < j; ++k)
          D[k] = 'R';
      } else if (D[i] == 'R' && D[j] == 'L') {
        int k = i + 1, l = j - 1;
        while (k < l)
          D[k++] = 'R', D[l--] = 'L';
      }
      i = j++;
    }
    return D.substr(1, n-2);
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.pushDominoes(".L.R...LR..L..").c_str());
  return 0;
}
