/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/permutations-ii/description/

#include <cstdio>
#include <vector>
#include <algorithm>

// 1 1 2
//
// 1 
//
// 1
//
// 2
class Solution {
 public:
  std::vector<std::vector<int>> m_r;
  void _solve(int step, std::vector<int> v, int start) {
    // for (int i = 0; i < step; ++i)
    //   printf("_");
    // printf("%d | ", start);
    // for (int i = 0; i < v.size(); ++i)
    //   printf("%d ", v[i]);
    // printf("\n");
    
    int n = v.size();

    // base condition
    if (start == n - 1) {
      m_r.push_back(v);
      return;
    }

    // recursion
    for (int i = start; i < n; ++i) {
      //
      if ((i != start) && (v[i] == v[start]))
        continue;
      std::swap(v[start], v[i]);
      _solve(step+1, v, start+1);
    }
  }
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& v) {      
    std::sort(v.begin(), v.end());
    _solve(0, v, 0);
    return m_r;
  }
};

int main() {
  // std::vector<int> v = {1, 2, 3};
  // std::vector<int> v = {1, 1, 3};
  // std::vector<int> v = {2, 2, 1, 1};
  std::vector<int> v = {1, 2, 2};
  
  Solution s;
  auto r = s.permuteUnique(v);

  for (auto rr : r) {
    for (int rrr : rr) {
      printf("%d ", rrr);
    }
    printf("\n");
  }
  
  return 0;
}
