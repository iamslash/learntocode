// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
 public:
  std::string largestNumber(std::vector<int>& V) {
    std::vector<std::string> VV;
    for (int i : V)
      VV.push_back(std::to_string(i));
    std::sort(VV.begin(), VV.end(), [](const std::string& lhs,
                                       const std::string& rhs) {
                return lhs+rhs > rhs+lhs;
              });
    std::string rslt;
    for (const auto& a : VV)
      rslt += a;
    // remove leading zeros
    while (rslt[0] == '0' && rslt.length() > 1)
      rslt.erase(0, 1);
    return rslt;
  }
};

int main() {
  // std::vector<int> V = {10, 2};
  std::vector<int> V = {3, 30, 34, 5, 9};

  Solution sln;
  printf("%s\n", sln.largestNumber(V).c_str());
  // std::string c = "123", d = "456";
  // bool b = c>d;
  // printf("%s\n", b ? "true" : "false");

  return 0;
}
