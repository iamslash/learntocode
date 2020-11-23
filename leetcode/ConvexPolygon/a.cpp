/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 44ms 100.00% 17Mb 80.00%
// cross product
// O(N) O(1)
class Solution {
 private:
  int crossprod(int px, int py, int qx, int qy) {
    return px*qy - py*qx;
  }
  int crossprod(int ox, int oy, int px, int py, int qx, int qy) {
    return crossprod(px-ox, py-oy, qx-ox, qy-oy);
  }
 public:
  bool isConvex(std::vector<std::vector<int>>& P) {
    int n = P.size();
    if (n < 2)
      return false;
    int64_t prv = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
      int j = (i+1)%n;
      int k = (i+2)%n;
      cur = crossprod(P[i][0], P[i][1], P[j][0], P[j][1], P[k][0], P[k][1]);
      if (cur == 0)
        continue;
      if (prv * cur < 0)
        return false;
      prv = cur;
    }
    return true;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

// (1,1) (0,1)
int main() {
  std::vector<std::vector<int>> P = {
    {0, 0},
    {0, 1},
    {1, 1},
    {1, 0}
  };
  // std::vector<std::vector<int>> P = {{0,0},{1,0},{1,1},{0,1}};

  Solution sln;
  printb(sln.isConvex(P));
         
  return 0;
}
