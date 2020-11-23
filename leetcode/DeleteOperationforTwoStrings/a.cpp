/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

void printC(std::vector<std::vector<int>>& C, int m, int n) {
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        printf("%d ", C[i][j]);
      }
      printf("\n");
    }
}

// Q. how can I choose a character to delete??? random???
// sea
// eat
//     e a t
//   0 0 0 0
// s 0 0 0 0
// e 0 1 1 1
// a 0 1 2 2

//     b
//   0 0
// a 0 0

// 16ms 98.44%
// Longest Common Subsequence
// O(N^2) O(N)
class Solution {
 private:
  int LCS(std::string a, std::string b) {
    int m = a.size();
    int n = b.size();
    std::vector<std::vector<int>> C(m+1, std::vector<int>(n+1,0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        C[i][j] = a[i-1] == b[j-1] ?
            C[i-1][j-1] + 1 :
            std::max(C[i-1][j], C[i][j-1]);
      }
    }
    // printC(C, m, n);    
    return C[m][n];
  }
 public:
  int minDistance(std::string a, std::string b) {
    return a.size() + b.size() - 2 * LCS(a, b);
  }
};

int main() {
  Solution sln;
  // printf("%d\n", sln.minDistance("sea", "eat"));  
  printf("%d\n", sln.minDistance("a", "b"));  
  return 0;
}
