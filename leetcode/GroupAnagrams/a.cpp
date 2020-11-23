/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/778/

#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> r;
    std::map<std::string, std::vector<std::string>> m;

    for (const auto& s : strs) {
      std::string a = s;
      std::sort(a.begin(), a.end());
      if (m.find(a) == m.end()) {
        m[a] = std::vector<std::string>();
      }
      m[a].push_back(s);
    }

    for (const auto& kv : m) {
      r.push_back(kv.second);
    }

    return r;
  }
};

int main() {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution s;
  std::vector<std::vector<std::string>> r = s.groupAnagrams(strs);
  
  // dump
  for (const auto& a : r) {
    for (const auto& b : a) {
      printf("%s ", b.c_str());
    }
    printf("\n");
  }
  
  return 0;
}
