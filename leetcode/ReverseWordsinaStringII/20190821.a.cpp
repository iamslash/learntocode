/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>


// i         j 
// a b c d e   f g

void printv(std::vector<char>& V) {
  for (char c : V)
    printf("%c", c);
  printf("\n");
}

// 64ms 99.16% 16.2MB 93.33%
// O(N) O(1)
class Solution {
 private:
  void reverse(std::vector<char>& V, int s, int e) {
    while (s < e)
      std::swap(V[s++], V[e--]);
  }
 public:
  void reverseWords(std::vector<char>& V) {
    int n = V.size();
    reverse(V, 0, n-1);
    // printv(V);
    int i = 0, j = 0;
    while (j < n) {
      while (j < n && V[j] != ' ')
        ++j;
      reverse (V, i, j-1);
      i = ++j;
    }
  }
};

int main() {

  std::vector<char> V = {
    't','h','e',' ',
    's','k','y',' ',
    'i','s',' ',
    'b','l','u','e'
  };

  Solution sln;
  sln.reverseWords(V);
  for (char c : V)
    printf("%c", c);
  printf("\n");
  
  return 0;
}
