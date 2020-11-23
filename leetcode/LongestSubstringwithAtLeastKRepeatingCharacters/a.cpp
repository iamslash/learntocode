/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

// // 668ms 5.30%
// class Solution {
//  public:
//   int longestSubstring(std::string s, int k) {
//     // base
//     if (s.size() == 0 || k > s.size())
//       return 0;

//     std::unordered_map<char, int> ump;
//     for (int i = 0; i < s.size(); ++i)
//       ump[s[i]]++;
//     int i = 0;
//     while (i < s.size() && ump[s[i]] >= k)
//       ++i;
//     if (i == s.size())
//       return s.size();
    
//     // recursion
//     int l = longestSubstring(s.substr(0, i), k);
//     int r = longestSubstring(s.substr(i+1), k);

//     return std::max(l, r);
//   }
// };

// 0ms 100.00%
class Solution {

 private:
  int solve(const std::string& s, int k, int start, int end) {
    // printf("start: %d, end: %d\n", start, end);
    
    std::unordered_map<char, int> freq;
    for (int i = start; i < end; ++i)
      freq[s[i]]++;
    int rslt = 0;
    for (int i = start; i < end;) {
      while (i < end && freq[s[i]] < k)
        ++i;
      if (i == end)
        break;
      int j = i;
      while (j < end && freq[s[j]] >= k)
        ++j;
      if (i == start && j == end)
        return end - start;
      rslt = std::max(rslt, solve(s, k, i, j));
      i = j;
    }

    return rslt;
  }

 public:
  int longestSubstring(std::string s, int k) {
    return solve(s, k, 0, s.size());
  }
};

int main() {

  Solution sln;
  
  printf("%d\n", sln.longestSubstring("aaabb", 3));
  printf("%d\n", sln.longestSubstring("ababbc", 2));
  
  return 0;
}
