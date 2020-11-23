/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 4ms 94.31% 8.3MB 100.00%
// DFS
// O(2^T) O(T)
class Solution {
 private:
  int m_ans = 0;
  void dfs(std::vector<int> &D, int n, int i) {
    // base
    if (i >= n)
      return;

    // recursion
    for (int j = 0; j < 26; ++j) {
      if (D[j] <= 0)
        continue;
      m_ans++;
      D[j]--;
      dfs(D, n, i+1);
      D[j]++;
    }

  }
 public:
  int numTilePossibilities(std::string T) {
    std::vector<int> D(26, 0);
    for (char c : T)
      D[c-'A']++;
    dfs(D, T.size(), 0);
    return m_ans;
  }
};

int main() {
  return 0;
}
