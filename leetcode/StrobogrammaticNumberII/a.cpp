/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>

// 0 1 2 3 4 5 6 7 8 9
// 0 1 X X X X 9 X 8 6

// 10 11 16 18 19
// 60 61 66 68 69
// 80 81 86 88 89
// 90 91 96 98 99

// 44ms 91.25% 25.7MB 48.48%
// Q. what is the range of n? n>0
// backtracking
class Solution {
 private:
  std::vector<std::string> solve(int rem, int all) {
    // base
    if (!rem)
      return {""};
    if (rem == 1)
      return {"0", "1", "8"};

    // recursion
    std::unordered_map<char, char> cands = {
      {'0', '0'},
      {'1', '1'},
      {'6', '9'},
      {'8', '8'},
      {'9', '6'}
    };
    auto nums = solve(rem-2, all);
    std::vector<std::string> rslt;
    for (auto& num : nums) {
      for (auto& pr : cands) {
        if (pr.first != '0' ||
            (pr.first == '0' && rem != all))
          rslt.push_back(pr.first + num + pr.second);
      }
    }
    return rslt;
  }
 public:
  std::vector<std::string> findStrobogrammatic(int n) {
    return solve(n, n);
  }
};

int main() {
  Solution sln;
  auto r = sln.findStrobogrammatic(4);
  for (auto& s : r)
    printf("%s\n", s.c_str());
  
  return 0;
}
