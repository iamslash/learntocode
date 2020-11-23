/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

auto __ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// abpcplea
// apple
// 28ms 100.00%
// O(ND) O(1)
class Solution {
 private:
  bool isIn(std::string n, std::string h) {
    int i = 0, j = 0;
    while (i < n.size() && j < h.size()) {
      if (n[i] == h[j])
        ++i;
      ++j;
      if (i == n.size())
        return true;
    }    
    return false;
  }
 public:
  std::string findLongestWord(const std::string& s, std::vector<std::string>& d) {
    std::string rslt;
    for (const auto& ss : d) {
      if ((ss.size() > rslt.size() && isIn(ss, s)) ||
          (ss.size() == rslt.size() && ss < rslt && isIn(ss, s))) {
        rslt = ss;
      } 
    }
    return rslt;
  }
};
 
int main() {

  // std::string s = "abpcplea";
  // std::vector<std::string> d = {"ale","apple","monkey","plea"};
  std::string s = "bab";
  std::vector<std::string> d = {"ba","ab","a","b"};
  
  Solution sln;
  printf("%s\n", sln.findLongestWord(s, d).c_str());
  return 0;
}
