/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>


//                i
// s: c d a d a b c c
// c: c d a b
//    2 1 2 1
// u: c d a b
//    1 1 1 1
// a: a d b c
//

//                        i
// s: b c b c b c a b a b a
// c: b c a
//    1 1 1
// u: b c a
//    1 1 1
// a: b c a

// 4ms 70.48% 8.4MB 100.00%
// monotone increasing
// O(N) O(N)
class Solution {
 public:
  std::string smallestSubsequence(std::string s) {
    std::string ans;
    std::vector<int> count(26), used(26);
    for (char c : s)
      count[c-'a']++;
    for (char c : s) {
      if (used[c-'a']) {
        count[c-'a']--;
        continue;
      }
      while (ans.size() &&
             ans.back() >= c &&
             used[ans.back()-'a'] < count[ans.back()-'a']) {
        count[ans.back()-'a']--;
        used[ans.back()-'a']--;
        ans.pop_back();
      }
      ans.push_back(c);
      used[c-'a']++;
    }
    return ans;
  }
};

int main() {
  return 0;
}
