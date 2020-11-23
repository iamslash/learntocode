/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

// 4ms 100.00%
class Solution {
 public:
  std::string largestNumber(const std::vector<int>& V) {
    std::vector<std::string> VV;
    for (int a : V)
      VV.push_back(std::to_string(a));
    std::sort(VV.begin(), VV.end(), [](const std::string& a,
                                       const std::string& b) {
                                      return a+b > b+a;
                                    });
    std::string rslt;
    for (const auto& vv : VV)
      rslt += vv;
    while (rslt.size() > 1 && rslt[0] == '0')
      rslt.erase(0, 1);
    return rslt;
  }
};

int main() {
  // std::vector<int> V = {10, 2};
  std::vector<int> V = {0, 0};
  // std::vector<int> V = {3, 30, 34, 5, 9};
  Solution sln;
  printf("%s\n", sln.largestNumber(V).c_str());
  
  return 0;
}
