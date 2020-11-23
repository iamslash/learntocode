/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

//  i
// 1432219 3
// 4ms 94.02%
class Solution {
 public:
  std::string removeKdigits(std::string N, int k) {
    std::string rslt;
    int keep = N.size() - k;
    for (int i = 0; i < N.size(); ++i) {
      while (rslt.size() > 0 & rslt.back() > N[i] && k > 0) {
        rslt.pop_back();
        --k;
      }
      rslt.push_back(N[i]);                                               
    }
    rslt.erase(keep);

    // trim head
    int i = 0;
    while (i < rslt.size()-1 && rslt[i] == '0')
      ++i;
    rslt.erase(0, i);

    return rslt == "" ? "0" : rslt;
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.removeKdigits("1432219", 3).c_str());
  printf("%s\n", sln.removeKdigits("10200", 1).c_str());
  printf("%s\n", sln.removeKdigits("10", 2).c_str());
  
  return 0;
}
