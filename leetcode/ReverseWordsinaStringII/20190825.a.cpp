/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

// 60ms 76.14% 16.4MB 55.56%
// O(N) O(1)
class Solution {
 public:
  void reverseWords(std::vector<char>& A) {
    int i = 0, j = 0, n = A.size();
    std::reverse(A.begin(), A.end());
    while (i < n) {
      j = i;
      while (j < n && A[j] != ' ')
        ++j;
      std::reverse(A.begin()+i, A.begin()+j);
      i = j+1;
    }        
  }
};

int main() {
  return 0;
}
