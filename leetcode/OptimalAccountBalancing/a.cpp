/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 36ms 68.25% 8.6MB 81.63%
// backtracking
// O(???) O(N)
class Solution {
 private:
  std::vector<int64_t> m_debts;
  int dfs(int i) {
    int n = m_debts.size();
    // skip zero debt
    while (i < n && !m_debts[i])
      ++i;
    int rslt = INT_MAX;
    int prev = 0;
    for (int j = i+1; j < n; ++j) {
      if (m_debts[j] != prev && m_debts[i] * m_debts[j] < 0) {
        m_debts[j] += m_debts[i];
        rslt = std::min(rslt, 1 + dfs(i + 1));
        m_debts[j] -= m_debts[i];
        prev = m_debts[j];
      }      
    }
    return rslt < INT_MAX ? rslt : 0;
  }
 public:
  int minTransfers(std::vector<std::vector<int>>& T) {
    std::unordered_map<int, int64_t> bals;
    for (auto& t : T) {
      bals[t[0]] -= t[2];
      bals[t[1]] += t[2];
    }
    for (auto& pr : bals) {
      if (pr.second)
        m_debts.push_back(pr.second);
    }
    return dfs(0);
  }
};

int main() {
  // std::vector<std::vector<int>> T = {
  //   {0, 1, 10},
  //   {2, 0, 5}
  // };
  std::vector<std::vector<int>> T = {
    {0, 1, 10},
    {1, 0, 1},
    {1, 2, 5},
    {2, 0, 5}
  };
  Solution sln;
  printf("%d\n", sln.minTransfers(T));
  
  return 0;
}
