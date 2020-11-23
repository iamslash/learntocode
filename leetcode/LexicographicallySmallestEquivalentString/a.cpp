/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <numeric>

// 4ms 80.59% 8.7MB 100.00%
// Disjoint Set
// O(max(A,S)) O(1)
class Solution {
 private:
  std::vector<char> m_prnt = std::vector<char>(26);
  void merge(char a, char b) {
    a = find(a), b = find(b);
    if (a == b)
      return;
    if (a < b)
      m_prnt[b-'a'] = a;
    else
      m_prnt[a-'a'] = b;
  }
  char find(char a) {
    if (a == m_prnt[a-'a'])
      return a;
    return m_prnt[a-'a'] = find(m_prnt[a-'a']);
  }
 public:
  std::string smallestEquivalentString(
      std::string A, std::string B, std::string S) {
    std::iota(m_prnt.begin(), m_prnt.end(), 'a');
    int m = A.size(), n = S.size();
    for (int i = 0; i < m; ++i)
      merge(A[i], B[i]);
    for (int i = 0; i < n; ++i)
      S[i] = find(S[i]);
    return S;
  }
};

int main() {
  return 0;
}
