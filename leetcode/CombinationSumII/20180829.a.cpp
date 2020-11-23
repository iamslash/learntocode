/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/combination-sum-ii/description/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

// 1 2 2 2 5
class Solution {
 public:
  std::set<std::vector<int>> m_r;
  void _combi(std::vector<int>& candi, int t,
              std::vector<int>& combi, int sum, int idx) {
    // printf("idx:%d sum:%d comb: ", idx, sum);
    // for (int i = 0; i < combi.size(); ++i)
    //   printf("%d ", combi[i]);
    // printf("\n");
    // base condition
    if (sum == t) {
      m_r.insert(combi);
      return;
    }
    if (idx >= candi.size())
      return;

    // recursion
    for (int i = idx; i < candi.size() && sum+candi[i] <= t; ++i) {
      // if (i > 0 && candi[i] == candi[i-1])
      //   continue;
      combi.push_back(candi[i]);
      _combi(candi, t, combi, sum + candi[i], i+1);
      combi.pop_back();
    }
  }
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candi, int t) {
    std::sort(candi.begin(), candi.end());
    std::vector<int> combi;
    _combi(candi, t, combi, 0, 0);
    return std::vector<std::vector<int>>(m_r.begin(), m_r.end());
  }
};

int main() {

  std::vector<int> v = {2, 5, 2, 1, 2};
  int t = 5;
  
  Solution s;
  auto r = s.combinationSum2(v, t);

  for (auto rr : r) {
    for (int b : rr) {
      printf("%d ", b);
    }
    printf("\n");
  }
  
  return 0;
}
