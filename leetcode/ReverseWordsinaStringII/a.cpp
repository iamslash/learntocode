/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 60ms 76.19% 16.2MB 100.00%
// O(N) O(1)
class Solution {
 public:
  void reverseWords(std::vector<char>& A) {
    int n = A.size(), i = 0, j;
    std::reverse(A.begin(), A.end());
    while (i < n) {
      j = i;
      while (j < n && A[j] != ' ')
        ++j;
      std::reverse(A.begin()+i, A.begin()+j);
      i = j + 1;
    }
  }
};

int main() {
  return 0;
}
