/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

// 4ms 100.00% 9.3MB 23.08%
// dfs backtracking with pruning
// O(N!) O(N)
class Solution {
 private:
  std::vector<bool> m_visit;
  std::vector<int> m_V;
  int m_tgt;
  bool solve(int pos, int k, int sum, int ord) {
    // base
    if (k == 1)
      return true;
    if (sum == m_tgt && ord > 0)
      return solve(0, k-1, 0, 0);

    // recursion
    for (int i = pos; i < m_V.size(); ++i) {
      if (m_visit[i] || m_V[i] + sum > m_tgt)
        continue;
      m_visit[i] = true;
      if (solve(i+1, k, sum+m_V[i], ord++))
        return true;
      m_visit[i] = false;
    }

    return false;
  }
 public:
  bool canPartitionKSubsets(std::vector<int>& V, int k) {
    std::sort(V.begin(), V.end(), std::greater<int>());
    int sum = std::accumulate(V.begin(), V.end(), 0);
    int rem = sum % k;
    if (rem)
      return false;
    m_visit = std::vector<bool>(V.size(), false);
    m_V = V;
    m_tgt = sum/k;
    return solve(0, k, 0, 0);
  }
};

int main() {

  std::vector<int> V = {4, 3, 2, 3, 5, 2, 1};
  int k = 4;
  Solution sln;
  printf("%s\n", sln.canPartitionKSubsets(V, k) ? "True" : "False");
  
  return 0;
}
