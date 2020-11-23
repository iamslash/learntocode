/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_map>

//  j
// i
// eceba

// 16ms 58.84% 9.9MB 36.18%
// O(N) O(N)
class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(std::string s) {
    int i = 0, j = 0, n = s.size(), maxcnt = 0;
    if (n <= 1)
      return n;
    std::unordered_map<char, int> ump;
    while (j < n) {
      ump[s[j]]++;
      while (ump.size() > 2) {
        ump[s[i]]--;
        if (ump[s[i]] <= 0)
          ump.erase(s[i]);
        ++i;
      }
      maxcnt = std::max(maxcnt, j - i + 1);
      ++j;
    }
    return maxcnt;
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.lengthOfLongestSubstringTwoDistinct("eceba"));
  printf("%d\n", sln.lengthOfLongestSubstringTwoDistinct("ccaabbb"));
  return 0;
}
