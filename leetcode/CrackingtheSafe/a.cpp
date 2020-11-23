/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 8ms 100.00% 12.5MB 4.65%
// O(K^N) O(K^N)
class Solution {
 private:
  int m_n;
  int m_k;
  int m_v;
  std::vector<std::vector<bool>> m_seen;
  std::string seq;
  void dfs(int u) {
    for (int v = 0; v < m_k; ++v) {
      if (!m_seen[u][v]) {
        m_seen[u][v] = true;
        dfs((u * m_k + v) % m_v);
        seq.push_back('0' + v);
      }
    }
  }
 public:
  std::string crackSafe(int n, int k) {
    if (k == 1)
      return std::string(n, '0');
    m_n = n;
    m_k = k;
    m_v = 1;
    for (int i = 0; i < n-1; ++i)
      m_v *= k;
    m_seen = std::vector<std::vector<bool>>(m_v, std::vector<bool>(k, false));
    dfs(0);
    return seq + seq.substr(0, n-1);
  }
};
 
int main() {
  Solution sln;
  // printf("%s\n", sln.crackSafe(1, 2).c_str());
  printf("%s\n", sln.crackSafe(2, 2).c_str());
  
  return 0;
}
