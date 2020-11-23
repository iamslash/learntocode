/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

// dynamic programming iterative way
// O(N*m*n) O(m*n)

//     s: 0001
// cnt_z: 3
// cnt_o: 1
//
// {"10", "0001", "111001", "1", "0"}
// 0 0 0 0
// 0 1 1 1
// 0 1 1 1
// 0 1 1 1
// 0 1 1 1
// 0 1 1 1

// 100ms 70.75% 10.1MB 62.60%
// O(SMN) O(MN)
class Solution {
 public:
  int findMaxForm(std::vector<std::string>& S, int m, int n) {
    // max count of m, n
    std::vector<std::vector<int>> C(m+1, std::vector<int>(n+1, 0));
    for (const auto& s : S) {
      int cnt0 = std::count(s.begin(), s.end(), '0') ;
      int cnt1 = s.size() - cnt0;

      for (int i = m; i >= cnt0; --i) {
        for (int j = n; j >= cnt1; --j) {
          C[i][j] = std::max(C[i][j], C[i-cnt0][j-cnt1]+1);
        }
      }
    }
    return C[m][n];
  }
};

int main() {

  // std::vector<std::string> V = {"10", "0001", "111001", "1", "0"};
  // int m = 5, n = 3;  
  std::vector<std::string> V = {"10", "0", "1"};
  int m = 1, n = 1;
  Solution sln;
  printf("%d\n", sln.findMaxForm(V, m, n));
  
  return 0;
}
