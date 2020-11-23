/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/combination-sum-ii/description/

#include <cstdio>
#include <vector>
#include <algorithm>

#include <iostream>
static int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
class Solution {
 public:
  std::vector<std::vector<int>> m_ans;
  std::vector<int> m_cand;
  std::vector<int> m_comb;
  void _solve(int start, int tgt) {
    // base condition
    if (tgt == 0) {
      m_ans.push_back(m_comb);
      return;
    } else if (tgt < 0) {
      return;
    }

    // recursion
    for (int i = start; i < m_cand.size() && m_cand[i] <= tgt; ++i) {
      if (i > start && m_cand[i] == m_cand[i-1])
        continue;
      m_comb.push_back(m_cand[i]);
      _solve(i + 1, tgt - m_cand[i]);
      m_comb.pop_back();
    }
  }  
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& cand, int t) {
    std::sort(cand.begin(), cand.end());
    m_cand = cand;
    _solve(0, t);
    return m_ans;
  }
};

int main() {
  // std::vector<int> cand = {2, 5, 2, 1, 2}; int t = 5;
  std::vector<int> cand = {10, 1, 2, 7, 6, 1, 5}; int t = 8;

  Solution s;
  auto r = s.combinationSum2(cand, t);

  for (auto rr : r) {
    for (int rrr : rr) {
      printf("%d ", rrr);
    }
    printf("\n");
  }
  
  return 0;
}
