/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <map>
#include <sstream>
#include <vector>

// // backtracking
// // 180ms 48.8MB
// class Solution {
//  public:
//   bool canWin(std::string s) {
//     for (int i = 1; i < s.size(); ++i) {
//       if (s[i-1] == '+' && s[i] == '+') {
//         s[i-1] = s[i] = '-';
//         if (!canWin(s))
//           return true;
//         s[i-1] = s[i] = '+';
//       }
//     }
//     return false;
//   }
// };

// // 56ms 58.05%% 12.8MB 71.43%
// class Solution {
//  private:
//   std::map<std::string, bool> m_smp;
//  public:
//   bool canWin(std::string s) {
//     // base
//     if (m_smp.count(s))
//       return m_smp[s];

//     bool& b = m_smp[s];
//     for (int i = 1; i < s.size(); ++i) {
//       if (s[i-1] == '+' && s[i] == '+') {
//         s[i-1] = s[i] = '-';
//         if (!canWin(s))
//           return b = true;
//         s[i-1] = s[i] = '+';
//       }
//     }
//     return b = false;
//   }
// };

// 4ms 100.00% 8.3MB 71.43%
// ++-++
class Solution {
 public:
  bool canWin(std::string s) {
    std::replace(s.begin(), s.end(), '-', ' ');
    std::istringstream iss(s);
    int rslt = 0;
    std::vector<int> C;
    for (std::string t; iss >> t; ) {
      int nt = t.size();
      while (C.size() <= nt) {
        std::string x = t;
        int i = 0;
        int j = C.size() - 2;
        while (i <= j)
          x[C[i++] ^ C[j--]] = '-';
        C.push_back(x.find('+'));
      }
      rslt ^= C[nt];
    }
    return rslt;
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.canWin("++++") ? "true" : "false");
  return 0;
}
