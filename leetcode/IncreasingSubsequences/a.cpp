/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <unordered_set>
#include <vector>

class Solution {
 private:
  std::vector<std::vector<int>> m_rslt;
  std::vector<int> m_best;
  void solve(int step, const std::vector<int>& V, int pos) {
    for (int i = 0; i < step; ++i)
      printf("_");
    printf("pos: %d\n", pos);
    if (m_best.size() > 1)
      m_rslt.push_back(m_best);
    std::unordered_set<int> ust;
    for (int i = pos; i < V.size(); ++i) {
      int num = V[i];
      if ((m_best.empty() || num >= m_best.back())
          && ust.count(num) == 0) {
        m_best.push_back(num);
        solve(step+1, V, i + 1);
        m_best.pop_back();
        ust.insert(num);
      }
    }
  }
 public:
  std::vector<std::vector<int>> findSubsequences(const std::vector<int>& V) {
    solve(0, V, 0);
    return m_rslt;
  }
};

int main() {
  // std::vector<int> V = {4, 6, 7, 7};
  std::vector<int> V = {4, 6, 4};
  Solution sln;
  auto rslt = sln.findSubsequences(V);
  for (const auto& l : rslt) {
    for (int a : l)
      printf("%d ", a);
    printf("\n");
  }
  
  return 0;
}
