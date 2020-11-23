/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>

//                 j
//     a b b a b a
//   a   0 0 1 0 1 
//   b     1 0 2 0
//   b       0 1 0
//   a         0 2
// i b           0
//   a  

// // 36ms 43.20% 49MB 50.00%
// // dynamic programming
// // O(N^2) O(N^2)
// class Solution {
//  public:
//   int longestRepeatingSubstring(std::string S) {
//     int ans = 0, n = S.size();

//     std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
//     for (int i = 0; i < n; ++i) {
//       for (int j = i+1; j < n; ++j) {
//         if (S[i] == S[j]) {
//           if (i > 0 && S[i-1] == S[j-1])
//             C[i][j] = C[i-1][j-1] + 1;
//           else 
//             C[i][j] = 1;
//           ans = std::max(ans, C[i][j]);
//         }
//       }
//     }

//     return ans;
//   }
// };

//   i
// a b c d

// 16ms 89.05% 13.7MB 50.00%
// hash map
// 
class Solution {
 public:
  int longestRepeatingSubstring(std::string S) {
    int n = S.size();
    if (n == 0)
      return 0;
    std::unordered_map<std::string, int> ump;
    int idx = 1, beg = 0, ans = 0;
    std::string tmp;
    while (idx <= n-1) {
      for (int i = 0; i < n - idx + 1; ++i) {
        tmp = S.substr(i, idx);
        ump[tmp]++;
        if (ump[tmp] == 2) {
          ans = idx;
          break;
        }
      }
      if (ans < idx)
        return ans;
      idx++;
      ump.clear();
    }
    return ans;
  }
};

int main() {
  return 0;
}
