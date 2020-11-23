/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// (100)
// 1   00
// 10   0

// 12ms 88.10% 12.8MB 43.52%
// cartesian product
// O(N^3) O(N)
class Solution {
 private:
  std::vector<std::string> solve(std::string s) {
    int n = s.size();
    if (n == 0 || (n > 1 && s[0] == '0' && s[n-1] == '0'))
      return {};
    if (n > 1 && s[0] == '0')
      return {"0." + s.substr(1)};      
    if (n == 1 || s[n-1] == '0')
      return {s};
    std::vector<std::string> rslt = {s};
    for (int i = 1; i < n; ++i)
      rslt.push_back(s.substr(0, i) + '.' + s.substr(i));
    return rslt;
  }
 public:
  std::vector<std::string> ambiguousCoordinates(std::string s) {
    std::vector<std::string> rslt;
    int n = s.size();
    for (int i = 1; i < n-2; ++i) {
      auto c = solve(s.substr(1, i));
      auto d = solve(s.substr(i+1, n-2-i));
      for (auto& e : c) {
        for (auto& f : d) {
          rslt.push_back("(" + e + ", " + f + ")");
        }
      }
    }
    return rslt;
  }
};

int main() {

  // std::string s = "(0123)";
  std::string s = "(100)";
  Solution sln;
  auto rslt = sln.ambiguousCoordinates(s);
  for (auto& s : rslt)
    printf("%s\n", s.c_str());
  
  return 0;
}
