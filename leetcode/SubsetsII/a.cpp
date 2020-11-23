// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/subsets-ii/description/

#include <cstdio>
#include <vector>
#include <algorithm>

// 1 2 2
//
// 1
// _ 1 2
// _ _ 1 2 2  
// _ 1 2     *
// 2
// _ 2 2
// 2         *
// recursive solution
// O(2^N) O(N)
// 4ms 100%
//
// class Solution {
//  public:
//   std::vector<std::vector<int>> m_r;  // result
//   std::vector<int> m_c;  // combination
//   std::vector<int> m_v;  // nums
//   void solve(int start) {
//     // printf("%d | ", start);
//     // for (int a : m_c)
//     //   printf("%d ", a);
//     // printf("\n");
//     if (start <= m_v.size()) {
//       m_r.push_back(m_c);
//     }

//     // recursion
//     for (int i = start; i < m_v.size(); ++i) {
//       if (i > start && m_v[i] == m_v[i-1])
//         continue;
//       m_c.push_back(m_v[i]);
//       solve(i + 1);
//       m_c.pop_back();
//     }
//   }
//   std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& v) {
//     std::sort(v.begin(), v.end());
//     m_v = v;
//     solve(0);
//     return m_r;
//   }
// };

// iterative solution
// O(N^2) O(1) 
// 12ms 14.86% Why it is worse than recursive solution???
//
// start: 0
//  size: 0
//     j: 0
// i
// 1 2 2
// r:
class Solution {
 public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& v) {
    std::vector<std::vector<int>> r = {{}};
    std::sort(v.begin(), v.end());
    int size = 0, start = 0;
    for (int i = 0; i < v.size(); ++i) {
      start = (i > 0 && v[i] == v[i-1]) ? size : 0;
      size  = r.size();
      for (int j = start; j < size; ++j) {
        r.push_back(r[j]);
        r.back().push_back(v[i]);
        printf("i: %d j: %d start: %d size: %d | ", i, j, start, size);
        for (int a : r.back())
          printf("%d ", a);
        printf("\n");
      }
    }
    return r;
  }
};

int main() {
  std::vector<int> v = {1, 2, 2};

  Solution s;
  auto r = s.subsetsWithDup(v);

  for (auto rr : r) {
    for (int a : rr) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}
