/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/833/

#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
// b
//     i
// -1, 0, 1, 1, 3,  4, 5, 6, 7,  8, 9
//  9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6
// O(NlgN)
// class Solution {
//  public:
//   int longestConsecutive(std::vector<int>& v) {
//     if (v.size() <= 1)
//       return v.size();
//     int r = 1, c = 1;
//     std::set<int> s(v.begin(), v.end());
//     int b = *s.begin();
//     auto it = s.begin();
//     ++it;
//     for (; it != s.end(); ++it) {
//       if (b+1 == *it)
//         ++c;
//       else
//         c = 1;
//       b = *it;
//       r = std::max(r, c);
//     }
//     return r;
//   }
// };

// slower than unordered_map. why???
// class Solution {
//  public:
//   int longestConsecutive(std::vector<int>& v) {
//     int r = 0;
//     std::unordered_set<int> s(v.begin(), v.end());
//     for(int a : s) {
//       if(s.find(a - 1) == s.end()) {
//         int cnt = 0;
//         for(int i = a; s.find(i) != s.end(); i++)
//           cnt++;
//         r = std::max(r, cnt);
//       }
//     }
//     return r;
//   }
// };

// The best solution
class Solution {
 public:
  int longestConsecutive(std::vector<int>& v) {
    int r = 0;
    std::unordered_map<int, int> m;
    for (int a : v)
      m[a] = 1;
    for (const auto& p : m) {
      if(m.find(p.first - 1) == m.end()) {
        int cnt = 0;
        for(int i = p.first; m.find(i) != m.end(); i++)
          cnt++;
        r = std::max(r, cnt);
      }
    }
    return r;
  }
};

int main() {
  // std::vector<int> v = {100, 4, 200, 1, 3, 2};
  // std::vector<int> v = {0, 0};
  std::vector<int> v = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
  Solution s;
  printf("%d\n", s.longestConsecutive(v));
  
  return 0;
}
