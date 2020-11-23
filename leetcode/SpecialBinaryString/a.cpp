/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>


//  i     
// 11011000
//   j

// 4ms 100.00% 8.9MB 88.24%
// O(N^2) O(N)
class Solution {
 public:
  std::string makeLargestSpecial(std::string s) {
    // base
    int n = s.size();
    if (n == 0)
      return s;

    // recursion
    int cnt = 0;
    std::vector<std::string> subsbs;  // sub special binary strings
    for (int i = 0, j = 0; j < s.size(); ++j) {
      cnt += (s[j] == '1' ? 1 : -1);
      if (cnt == 0) {
        subsbs.push_back('1' + makeLargestSpecial(s.substr(i+1,j-i-1)) + '0');
        i = j + 1;
      }
    }
    std::sort(subsbs.begin(), subsbs.end(), std::greater<std::string>());
    std::string rslt;
    for (auto& a : subsbs)
      rslt += a;
    return rslt;
  }
};

int main() {

  Solution sln;
  printf("%s\n", sln.makeLargestSpecial("11011000").c_str());
  
  return 0;
}
