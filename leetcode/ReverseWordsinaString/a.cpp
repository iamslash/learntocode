/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// the sky is blue
// eulb si yks eht
// blue is sky the
//      i
//     j

// 8ms 78.79% 10.7MB 59.46%
// brute force
// O(N) O(N)
class Solution {
 public:
  std::string reverseWords(std::string s) {
    int n = s.size(), i = 0, j;
    std::reverse(s.begin(), s.end());
    std::string ans;
    while (i < n) {
      while (i < n && s[i] == ' ')
        ++i;
      j = i;
      while (j < n && s[j] != ' ')
        ++j;
      // printf("%d %d\n", i, j);
      std::reverse(s.begin() + i, s.begin() + j);
      ans += s.substr(i, j - i) + ' ';
      i = j + 1;
    }
    while (ans.size() && ans.back() == ' ')
      ans.pop_back();
    return ans;
  }
};

int main() {

  Solution sln;
  printf("%s\n", sln.reverseWords("the sky is blue").c_str());
  
  return 0;
}
