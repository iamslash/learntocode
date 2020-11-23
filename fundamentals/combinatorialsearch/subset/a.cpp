/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

class Solution {
 private:
  std::vector<int> m_comb;
  std::vector<std::vector<int>> m_rslt;
  int m_n;
  void solve(int pos) {
    // for (int i = 0; i < pos; ++i) 
    //   printf("_");
    // printf("%d\n", pos);
    
    // base
    if (pos > 0) {
      m_rslt.push_back(m_comb);
    }
    // recursion
    for (int i = pos + 1; i <= m_n; ++i) {
      m_comb.push_back(i);
      solve(i);
      m_comb.pop_back();
    }
  }
 public:
  std::vector<std::vector<int>> subset(int n) {
    m_n = n;
    solve(0);
    m_rslt.push_back({});
    return m_rslt;
  }
};

int main() {

  Solution sln;
  auto rslt = sln.subset(4);
  for (const auto& l : rslt) {
    for (int a : l) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}
