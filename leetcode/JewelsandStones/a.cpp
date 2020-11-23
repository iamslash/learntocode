/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_set>

// 9ms 99.42% 10.2MB 10.51%
// O(S) O(J)
class Solution {
 public:
  int numJewelsInStones(std::string J, std::string S) {
    std::unordered_set<char> ust(J.begin(), J.end());
    return std::count_if(S.begin(), S.end(), [&ust](const char c) {
        return ust.count(c) > 0;
      });
  }
};

int main() {
  std::string J = "aA";
  std::string S = "aAAbbbb";
  Solution sln;
  printf("%d\n", sln.numJewelsInStones(J, S));
  
  return 0;
}
