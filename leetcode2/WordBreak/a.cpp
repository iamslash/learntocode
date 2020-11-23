/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

//           i
// s: leetcode
// D: leet code
//
// Iterative way
// 4ms 84.58%
// class Solution {
//  public:
//   bool wordBreak(std::string s, std::vector<std::string>& D) {
//     int n = s.size();
//     std::vector<bool> C(n+1, false);
//     C[n] = true;

//     for (int i = n-1; i >= 0; --i) {
//       for (const std::string& d : D) {
//         if ((i + d.size() <= n) &&
//             (s.substr(i, d.size()).compare(d) == 0)) {
//           C[i] = C[i+d.size()];
//           if (C[i])
//             break;
//         }
//       }
//     }
//     return C[0];
//   }
// };

// Recursive way
// 0ms 100.00%
class Solution {
 private:
  std::vector<bool> m_C;
  bool solve(std::string s, std::vector<std::string>& D, int i) {
    for (const auto& word : D) {
      int j = i + word.size();
      if (j > s.size())
        continue;
      bool match = true;
      for (int k = 0; k < word.size(); ++k) {
        if (s[i+k] != word[k]) {
          match = false;
          break;
        }
      }
      if (match) {
        if (j == s.size())
          return true;
        if (!m_C[j] && solve(s, D, j))
          return true;
      }
    }
    m_C[i] = true;
    return false;
  }
        
 public:
  bool wordBreak(std::string s, std::vector<std::string>& D) {
    m_C.resize(s.size(), false);
    return solve(s, D, 0);
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  std::string s = "leetcode";
  std::vector<std::string> D = {"leet", "code"};
  // std::string s = "applepenapple";
  // std::vector<std::string> D = {"apple", "pen"};

  Solution sln;
  printb(sln.wordBreak(s, D));
  
  return 0;
}
