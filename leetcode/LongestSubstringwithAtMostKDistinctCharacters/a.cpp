/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_map>

// j
// a

// // 32ms 14.81% 10.5MB 11.81%
// // O(N) O(N)
// class Solution {
//  public:
//   int lengthOfLongestSubstringKDistinct(std::string s, int k) {
//     if (k == 0)
//       return 0;
    
//     int maxlen = 0;

//     int i = 0;
//     int j = 0;
//     int n = s.size();

//     // char : count
//     std::unordered_map<char, int> ump;

//     for (int j = 0; j < n; ++j) {
//       ump[s[j]]++;
//       while (i < j && ump.size() > k) {
//         char c = s[i];
//         if (--ump[s[i]] <= 0)
//           ump.erase(s[i]);
//         ++i;
//       }
//       maxlen = std::max(maxlen, j - i + 1);
//     }
    
//     return maxlen;
//   }
// };

// 8ms 99.26% 9.2MB 56.25%
// O(N) O(1)
class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(std::string s, int k) {
    int c2cnt[256] = {};
    int i = -1;
    int distinct = 0;
    int maxlen = 0;
    for (int j = 0; j < s.size(); ++j) {
      distinct += c2cnt[s[j]]++ == 0;
      while (distinct > k)
        distinct -= --c2cnt[s[++i]] == 0;
      maxlen = std::max(maxlen, j - i);
    }
    return maxlen;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.lengthOfLongestSubstringKDistinct("eceba", 2));
  printf("%d\n", sln.lengthOfLongestSubstringKDistinct("aa", 1));
  printf("%d\n", sln.lengthOfLongestSubstringKDistinct("a", 0));
  
  return 0;
}
