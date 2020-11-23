/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/846/

#include <cstdio>
#include <vector>


class Solution {
 public:
  std::vector<std::vector<int>> m_M;  // Matrix
  std::vector<bool> m_V;  // visited
  int m_N;
  void dfs(int i) {
    // printf("%d %d\n", y, x);
    m_V[i] = true;
    for (int j = 0; j < m_N; ++j) {
      if (m_V[j] || m_M[i][j] == 0)
        continue;
      dfs(j);
    }
  }

  int findCircleNum(std::vector<std::vector<int>>& M) {
    if (M.empty() || M[0].empty())
      return 0;
    m_M = M;
    m_N = M.size();
    m_V.resize(m_N, false);

    int rslt = 0;
    for (int i = 0; i < m_N; ++i) {
      if (m_V[i])
        continue;
          // printf("%d %d\n", y, x);
      dfs(i);
      rslt++;
    }
    return rslt;
  }
};

int main() {
  std::vector<std::vector<int>> M = {
    {1, 1, 0},
    {1, 1, 0},
    {0, 0, 1},
  };
  // std::vector<std::vector<int>> M = {
  //   {1, 1, 0},
  //   {1, 1, 1},
  //   {0, 1, 1},
  // };
  // std::vector<std::vector<int>> M = {
  //   {1, 0, 0, 1},
  //   {0, 1, 1, 0},
  //   {0, 1, 1, 1},
  //   {1, 0, 1, 1},
  // };
  Solution s;
  printf("%d\n", s.findCircleNum(M));
  return 0;
}
