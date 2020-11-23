/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/find-and-replace-pattern/description/

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string normalize(std::string s) {
    std::string r;
    std::unordered_map<char, int> m;
    for (char c : s) {
      if (!m.count(c))
        m[c] = m.size();
      r += m[c];
    }
    return r;
  }
  std::vector<std::string> findAndReplacePattern(
      std::vector<std::string>& W, std::string p) {
    std::vector<std::string> r;
    p = normalize(p);
    for (const auto& w : W) {
      if (normalize(w) == p)
        r.push_back(w);
    }
    return r;
  }
};

int main() {
  std::vector<std::string> W = {
    "abc",
    "deq",
    "mee",
    "aqq",
    "dkd",
    "ccc",
  };
  std::string p = "abb";
  
  Solution s;
  auto r = s.findAndReplacePattern(W, p);

  for (auto rr : r) {
    printf("%s\n", rr.c_str());
  }
  printf("\n");
  
  return 0;
}
