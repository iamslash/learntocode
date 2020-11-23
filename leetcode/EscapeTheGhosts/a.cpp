// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <cmath>

// 4ms 96.24%
class Solution {
 private:
  int getDist(int y0, int x0, int y1, int x1) {
    return std::abs(y1-y0) + std::abs(x1-x0);
  }
 public:
  bool escapeGhosts(const std::vector<std::vector<int>>& G,
                    const std::vector<int>& T) {
    int dist = getDist(0, 0, T[0], T[1]);
    for (int i = 0; i < G.size(); ++i) {
      if (getDist(T[0], T[1], G[i][0], G[i][1]) <= dist)
        return false;
    }
    return true;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  std::vector<std::vector<int>> G0 = {{1, 0}, {0, 3}};
  std::vector<int> T0 = {0, 1};
  std::vector<std::vector<int>> G1 = {{1, 0}};
  std::vector<int> T1 = {2, 0};
  std::vector<std::vector<int>> G2 = {{2, 0}};
  std::vector<int> T2 = {1, 0};
  
  Solution sln;
  printb(sln.escapeGhosts(G0, T0));
  printb(sln.escapeGhosts(G1, T1));
  printb(sln.escapeGhosts(G2, T2));
  
  return 0;
}
