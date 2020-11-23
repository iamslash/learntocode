/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <string>

using namespace std;

//           i
//      s: p w w k e w
//             j
// cntMap: p w
//         1 2
//    ans: 1

// 36ms 53.29% 8.4MB 5.03%
// two pointers
// O(N) O(N)
class Solution {
 public:
  int lengthOfLongestSubstring(string& s) {
    if (s.size() == 0)
      return 0;
    int ans = 0, i = 0, j = 0;
    unordered_map<char, int> cntMap;
    while (j < s.size()) {
      cntMap[s[j]]++;
      // forward i
      while (i < j && cntMap[s[j]] > 1) {
        cntMap[s[i]] = max(0, --cntMap[s[i]]);
        ++i;
      }
      ans = max(ans, j-i+1);
      // forward j
      ++j;
    }
    return ans;
  }
};

// 8ms 91.33% 8.4MB 5.03%
// two pointers
// O(N) O(N)
class Solution {
 public:
  int lengthOfLongestSubstring(string& s) {
    if (s.size() == 0)
      return 0;
    int ans = 0, i = 0, j = 0;
    vector<int> cnts(256);
    while (j < s.size()) {
      cnts[s[j]]++;
      // forward i
      while (i < j && cnts[s[j]] > 1) {
        cnts[s[i]] = max(0, --cnts[s[i]]);
        ++i;
      }
      ans = max(ans, j-i+1);
      // forward j
      ++j;
    }
    return ans;
  }
};

int main() {
  return 0;
}
