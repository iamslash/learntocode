/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

// z y
// a z : (25 + 26) % 26 = 25
// z a : (-25 + 26) % 26 = 1

// 8ms 98.68% 9.9MB 56.00%
// O(N) O(N)
class Solution {
 private:
  std::string hash(std::string s) {
    std::string rslt;
    int tmp = 0;
    for (int i = 1; i < s.size(); ++i) {
      tmp = (s[i] - s[i-1] + 26) % 26;
      rslt += 'A' + tmp;
    }
    return rslt;
  }
 public:
  std::vector<std::vector<std::string>> groupStrings(
      std::vector<std::string>& S) {
    if (S.empty())
      return {};
    std::vector<std::vector<std::string>> rslt;
    std::unordered_map<std::string, std::vector<std::string>> ump;
    for (auto& s : S)
      ump[hash(s)].push_back(s);
    for (auto& pr : ump)
      rslt.push_back(pr.second);
    return rslt;
  }
};

int main() {
  std::vector<std::string> S = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
  // std::vector<std::string> S = {"ab", "ba"};
  Solution sln;
  auto r = sln.groupStrings(S);
  for (auto& l : r) {
    for (auto& s : l)
      printf("%s ", s.c_str());
    printf("\n");
  }
  
  return 0;
}
