/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>

// "  hello world!  "
//    i    j
//          i     j

// // 12ms 39.53% 11MB 43.24%
// // O(N) O(N)
// class Solution {
//  public:
//   std::string reverseWords(std::string s) {
//     int i = 0, j = 0, n = s.size();
//     std::string ans;
//     std::reverse(s.begin(), s.end());
//     while (i < n) {
//       while (i < n && s[i] == ' ')
//         ++i;
//       j = i;
//       while (j < n && s[j] != ' ')
//         ++j;
//       std::string word = s.substr(i, j - i);
//       std::reverse(word.begin(), word.end());
//       ans += word + " ";
//       i = j+1;
//     }
//     while (ans.size() && ans.back() == ' ')
//       ans.pop_back();
//     return ans;
//   }
// };

// 0ms 100.00% 10.4MB 64.86%
// O(N) O(1)
class Solution {
 public:
  std::string reverseWords(std::string s) {
    std::reverse(s.begin(), s.end());
    std::istringstream iss(s);
    s = "";
    std::string w;
    while (std::getline(iss, w, ' ')) {
      if (w == "")
        continue;
      std::reverse(w.begin(), w.end());
      s += w + " ";
    }
    while (s.size() && s.back() == ' ')
      s.pop_back();
    return s;
  }
};

int main() {
  return 0;
}
