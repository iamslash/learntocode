/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/793/

#include <cstdio>
#include <vector>
#include <string>


// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
 public:
  std::string a;
  std::vector<std::string> r;
  std::vector<std::vector<char>> n;
  void _solve(int i, const std::string& d) {
    // base condition
    if (i >= d.size()) {
      r.push_back(a);
      return;
    }

    // check skip
    int j = d[i]-'2';
    if (j < 0 || j > 7) {
      _solve(i+1, d);
      return;
    }

    // recursion
    for (int k = 0; k < n[j].size(); ++k) {
      char c = n[j][k];
      a[i] = c;
      _solve(i+1, d);
    }
  }
  std::vector<std::string> letterCombinations(std::string d) {
    if (d.empty())
      return r;
    n = std::vector<std::vector<char>> {{'a','b','c'},
                                        {'d','e','f'},
                                        {'g','h','i'},
                                        {'j','k','l'},
                                        {'m','n','o'},
                                        {'p','q','r', 's'},
                                        {'t','u','v'},
                                        {'w','x','y', 'z'}};
    a = std::string(d.size(), ' ');
    _solve(0, d);
    return r;
  }
};

int main() {
  std::string a = "23";

  Solution s;
  std::vector<std::string> r = s.letterCombinations(a);
  for (const auto& e : r) {
    printf("%s\n", e.c_str());
  }
  return 0;
}
