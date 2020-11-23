/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

// 4ms 99.90%
// back tracking
// O(AC) O(AC)
class Solution {
 private:
  int m_rslt;
  std::vector<int> m_coins;
  void _dfs(int tgt, int idx, int lcnt) {
    // base condition
    if (idx < 0)
      return;
    int ccnt = tgt/m_coins[idx];  // current count
    if (tgt % m_coins[idx] == 0) {
      m_rslt = std::min(m_rslt, lcnt + ccnt);
      return;
    }
    if (lcnt + ccnt >= m_rslt - 1)
      return;

    // recursion
    for (int i = ccnt; i >= 0; --i)
      _dfs(tgt - i*m_coins[idx], idx - 1, lcnt + i);
  }
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    m_rslt = std::numeric_limits<int>::max();
    std::sort(coins.begin(), coins.end());
    m_coins = coins;
    _dfs(amount, coins.size()-1, 0);
    return (m_rslt == std::numeric_limits<int>::max()) ? -1 : m_rslt;
  }
};

Int main() {
  std::vector<int> coins = {1, 2, 5};
  int amount = 11;
  // std::vector<int> coins = {2};
  // int amount = 3;
  
  Solution sln;
  printf("%d\n", sln.coinChange(coins, amount));
  
  return 0;
}
