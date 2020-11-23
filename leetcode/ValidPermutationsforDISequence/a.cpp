/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_set>
#include <map>
#include <numeric>
#include <vector>

// D I D
// 1
// 2 1 3
//     4 3
// 2 3
// 2 4
// 3 1 2 
//     4 2
// 3 2 4 1
// 3 4
// 4 1 2
//     3 2
//   2 3 1
//   3

// 1 1 1 1 1
// 0 0 0 0 0
// 0 0 0 0 0


// 0ms 100.00% 9.7MB 100.00%
// dynamic programming
// O(N^2) O(N^2)
class Solution {
 public:
  int numPermsDISequence(std::string seq) {
    int mod = 1e9+7;
    int n = seq.size();
    // C[i][j] : 
    std::vector<std::vector<int>> C(n+1, std::vector<int>(n+1, 0));
    for (int j = 0; j <= n; ++j)
      C[0][j] = 1;
    for (int i = 0; i < n; ++i) {
      if (seq[i] == 'I') {
        for (int j = 0, k = 0; j < n - i; ++j) {
          k = C[i+1][j] = (k + C[i][j]) % mod;
        }
      } else {
        for (int j = n-i-1, k = 0; j >= 0; --j) {
          k = C[i+1][j] = (k + C[i][j+1]) % mod;
        }
      }
    }
    return C[n][0];
  }
};

int main() {
  std::string s = "DID";

  Solution sln;
  printf("%d\n", sln.numPermsDISequence(s));
  
  return 0;
}
