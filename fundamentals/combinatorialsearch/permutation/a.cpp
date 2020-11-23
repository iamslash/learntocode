/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <unordered_set>
#include <vector>

void printv(const std::vector<int>& V) {
  printf("  ");
  for (int a : V) 
    printf("%d ", a);
  printf("\n");
}

// backtracking
// O(N!) O(N)
class Solution {
 private:
  int m_n;
  std::vector<std::vector<int>> m_rslt;
  std::vector<int> m_comb;
  void solve(int l, int r) {
    // base
    if (l == r) {
      m_rslt.push_back(m_comb);
      return;
    }

    // recur
    for (int i = l; i <= r; ++i) {
      std::swap(m_comb[l-1], m_comb[i-1]);
      solve(l+1, r);
      std::swap(m_comb[l-1], m_comb[i-1]);    
    }
  }
 public:
  std::vector<std::vector<int>> permutate(int n) {
    m_n = n;
    for (int i = 1; i <= n; ++i) {
      m_comb.push_back(i);
    }
    solve(1, n);
    return m_rslt;
  }
};

int main() {

  Solution sln;
  auto rslt = sln.permutate(4);
  for (const auto& l : rslt) {
    for (int a : l) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}
