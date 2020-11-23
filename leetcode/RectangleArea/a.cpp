/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//     ---- (C,D)
//     |  |
//     ----
// (A,B)
//     ---- (G,H)
//     |  |
//     ----
// (E,F)

// 8ms 98.14% 8.4MB 5.43%
class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int64_t area = (int64_t)(C-A)*(D-B) + (int64_t)(G-E)*(H-F);
    if (C <= E || A >= G || B >= H || D <= F)
      return area;
    // return area - inter
    std::vector<int> xs = {A, C, E, G};
    std::vector<int> ys = {B, D, F, H};
    std::sort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());
    int64_t intr = (int64_t)(xs[2]-xs[1]) * (int64_t)(ys[2]-ys[1]);
    return area - intr;
  }
};

int main() {
  return 0;
}
