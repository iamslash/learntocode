// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <string>
#include <vector>

// O(N) O(N)
// class Solution {
//  public:
//   void reverseWords(std::string &s) {
//     std::vector<std::string> rslt;
//     std::string buf;
//     for (int i = s.size() - 1; i >= 0; --i) {
//       if (s[i] == ' ') {
//         if (!buf.empty()) {
//           rslt.push_back(buf);
//           // printf("%s\n", buf.c_str());
//         }
//         buf = "";
//       } else if (i == 0) {
//         if (s[i] != ' ') {
//           buf.insert(buf.begin(), s[i]);
//           rslt.push_back(buf);
//         }       
//       } else {
//         buf.insert(buf.begin(), s[i]);
//         // printf("%c\n", s[i]);
//       }
//     }
//     s = "";
//     for (int i = 0; i < rslt.size(); ++i) {
//       if (i > 0)
//         s += " ";
//       s += rslt[i];
//     }
//   }
// };

// the sky is blue
// i
// eulb si yks eht
// blue is sky the
// O(N^2) O(1)
class Solution {
 public:
  void reverseWords(std::string &s) {
    std::reverse(s.begin(), s.end());
    int i = 0;
    while (i < s.size()) {
      if (s[i] == ' ') {
        i++;
        continue;
      }
      //
      int j = i + 1;
      while (j < s.size() && s[j] != ' ') {
        j++;
      }
      // printf("%d %d\n", i, j);
      std::reverse(s.begin()+i, s.begin()+j);
      i = j;
    }
  }
};

int main() {
  std::string s = "the sky is blue";
  Solution sln;
  sln.reverseWords(s);
  printf("%s\n", s.c_str());
  
  return 0;
}
