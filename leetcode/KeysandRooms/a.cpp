// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>

class Solution {
 private:
  std::vector<std::vector<int>> m_adj;
  std::vector<bool> m_visited;
  void dfs(int step, int u) {
    // for (int i = 0; i < step; ++i)
    //   printf("_");
    // printf("%d\n", u);
    m_visited[u] = true;
    for (int v : m_adj[u]) {
      if (!m_visited[v])
        dfs(step+1, v);
    }
  }
 public:
  bool canVisitAllRooms(const std::vector<std::vector<int>>& R) {
    m_adj = R;
    m_visited.resize(R.size(), false);
    dfs(0, 0);
    return std::all_of(m_visited.begin(), m_visited.end(),
                       [](bool b){ return b == true; });
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}
int main() {
  std::vector<std::vector<int>> R0 = {
    {1},
    {2},
    {3},
    {}
  };
  std::vector<std::vector<int>> R1 = {
    {1, 3},
    {3, 0, 1},
    {2},
    {0}
  };

  Solution sln;
  //printb(sln.canVisitAllRooms(R0));
  printb(sln.canVisitAllRooms(R1));
}
