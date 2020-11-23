/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// i
// j
// AABABBA

// // sliding window
// // 8ms 72.51%
// class Solution {
//  public:
//   int characterReplacement(std::string s, int k) {
//     if (s.empty())
//       return 0;
//     std::vector<int> cnts(26, 0);
//     int i = 0, j = 0, max_cnt = 0;
//     for (; j < s.size(); ++j) {
//       max_cnt = std::max(max_cnt, ++cnts[s[j]-'A']);
//       if (j - i + 1 - max_cnt > k) {
//         cnts[s[i++]-'A']--;
//       }
//     }
//     return j - i;
//   }
// };

// 12ms 56.14%
class Solution {
 public:
  int characterReplacement(std::string s, int k) {
    int n = s.size();
    std::vector<int> cnts(26, 0);
    int i = 0, max_cnt = 0, max_len = 0;
    for (int j = 0; j < n; ++j) {
      max_cnt = std::max(max_cnt, ++cnts[s[j]-'A']);
      while (j - i + 1 - max_cnt > k) {
        cnts[s[i++]-'A']--;
      }
      max_len = std::max(max_len, j - i + 1);
    }
    return max_len;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.characterReplacement("ABAB", 2));
  printf("%d\n", sln.characterReplacement("AABABBA", 1));
  
  return 0;
}
