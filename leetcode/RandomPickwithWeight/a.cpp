/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

// 100ms 98.92%
// pickIndex: O(lgN) O(N)
class Solution {
 private:
  std::vector<int> m_ps;  // partial sum
  int m_total;
 public:
  Solution(std::vector<int> W) {
    m_total = 0;
    for (int n : W) {
      m_total += n;
      m_ps.push_back(m_total);
    }
  }
    
  int pickIndex() {
    int pos = rand() % m_total;
    auto it = std::upper_bound(m_ps.begin(), m_ps.end(), pos);
    return it - m_ps.begin();
  }
};

int main() {
  std::vector<int> V = {1, 1};
  Solution sln(V);
  for (int i = 0; i < 5; ++i) {
    printf("%d\n", sln.pickIndex());
  }
  
  return 0;
}
