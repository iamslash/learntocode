// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

// one include other ???
class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    std::vector<int> xs(4, 0);
    std::vector<int> ys(4, 0);
    xs[0] = A; xs[1] = C; xs[2] = E; xs[3] = G;
    ys[0] = B; ys[1] = D; ys[2] = F; ys[3] = H;
    std::sort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());
    int inter = (ys[2] - ys[1]) * (xs[2] - xs[1]);
    int total = abs(C-A) * abs(D-B) + abs(G-E) * abs(H-F);
    return total - inter;
  }
};
int main() {
  // std::vector<int> V = {-3, 0, 3, 4, 0, -1, 9, 2};
  std::vector<int> V = {-2, -2, 2, 2, 3, 3, 4, 4};
  Solution sln;
  printf("%d\n", sln.computeArea(V[0], V[1], V[2], V[3],
                                 V[4], V[5], V[6], V[7]));
  return 0;
}
